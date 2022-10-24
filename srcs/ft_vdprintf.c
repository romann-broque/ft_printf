/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/24 16:33:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_option(t_machine *machine)
{
	const ssize_t	option_index = get_index(OPTIONS, *machine->input);

	print(machine, option_index);
	machine->flags = NO_FLAG;
	machine->width = 0;
	machine->state = E_IDLE;
}

void	get_flag(t_machine *machine)
{
	const ssize_t	flag_index = get_index(FLAGS, *machine->input);
	ssize_t			i;
	uint8_t			flag;

	flag = NO_FLAG;
	i = 0;
	while (i <= flag_index)
	{
		flag <<= 1;
		++i;
	}
	machine->flags |= flag;
	machine->state = E_OPTION;
}

void	get_width(t_machine *machine)
{
	machine->width = machine->width * 10 + *machine->input - '0';
	machine->state = E_OPTION;
}

void	print_unknown(t_machine *machine)
{
	const char	option_char = OPTION_CHAR;

	if (*(machine->input + 1) != '\0')
	{
		cpy_data(machine, (char *)(&option_char), sizeof(char));
		if (*(machine->input + 2) != '\0')
			cpy_data(machine, machine->input, sizeof(char));
	}
	machine->state = E_IDLE;
}

static void	get_data(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (ft_strchr(OPTIONS, curr_c))
		get_option(machine);
	else if (ft_strchr(FLAGS, curr_c) != NULL)
		get_flag(machine);
	else if (ft_isdigit(curr_c) != 0)
		get_width(machine);
	else
		print_unknown(machine);
}

static enum e_state	get_next_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == '\0')
		machine->state = E_END;
	else if (machine->state == E_OPTION)
		get_data(machine);
	else if (curr_c == OPTION_CHAR)
		machine->state = E_OPTION;
	else
		cpy_data(machine, (char *)(&curr_c), sizeof(char));
	return (machine->state);
}

int	ft_vdprintf(int fd, const char *str, va_list aptr)
{
	t_machine	*machine;
	char		*output;

	machine = init_machine(str, aptr, fd);
	output = NULL;
	while (get_next_state(machine) != E_END)
	{
		if (machine->index >= BUFFER_SIZE)
		{
			output = strnjoin(output, machine->buffer, BUFFER_SIZE);
			output = strnjoin(output, machine->rest, BUFFER_SIZE);
			ft_bzero(machine->buffer, BUFFER_SIZE);
			ft_bzero(machine->rest, BUFFER_SIZE);
			machine->index -= BUFFER_SIZE;
			++(machine->nbof_buffer);
		}
		++(machine->input);
	}
	output = strnjoin(output, machine->buffer, BUFFER_SIZE);
	write(fd, output, machine->nbof_buffer * BUFFER_SIZE + machine->index);
	free(output);
	free(machine);
	return (EXIT_SUCCESS);
}

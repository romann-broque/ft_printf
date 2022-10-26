/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 15:38:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(t_machine *machine, const ssize_t flag_index)
{
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
}

void	get_width(t_machine *machine)
{
	machine->width = machine->width * 10 + *machine->input - '0';
	machine->state = E_MOD;
}

char	*fill_unknown(t_machine *machine)
{
	char		*string;
	size_t		len;

	len = (machine->input[0] != '\0' && machine->input[1] != '\0') + (machine->input[2] != '\0');
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string != NULL)
	{
		string[len] = '\0';
		if (len > 0)
			string[0] = OPTION_CHAR;
		if (len > 1)
			string[1] = *machine->input;
	}
	return (string);
}

static size_t	conv_state(t_machine *machine)
{
	static char		*(*fill_arg[NBOF_OPTIONS])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};
	const char		curr_c = *machine->input;
	char			*string;
	ssize_t			option_index;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
		string = fill_arg[option_index](machine);
	else
		string = fill_unknown(machine);
	cpy_data(machine, string, ft_strlen(string));
	free(string);
	machine->flags = NO_FLAG;
	machine->width = 0;
	machine->state = E_STANDARD;
	return (ft_strlen(string) > 0);
}

static size_t mod_state(t_machine *machine)
{
	const char	curr_c = *machine->input;
	size_t		input_offset;
	ssize_t		flag_index;

	input_offset = 0;
	flag_index = get_index(FLAGS, curr_c);
	if (flag_index > -1)
	{
		get_flag(machine, flag_index);
		++input_offset;
	}
	else
		machine->state = E_CONV;
//	else if (ft_isdigit(curr_c) != 0)
//		get_width(machine);
	return (input_offset);
}

static size_t	standard_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == '\0') // END_CHAR
		machine->state = E_END;
	else if (curr_c == OPTION_CHAR)
		machine->state = E_MOD;
	else
		cpy_data(machine, (char *)(&curr_c), sizeof(char));
	return (1);
}

int	ft_vdprintf(int fd, const char *str, va_list aptr)
{
	static size_t	(*state_function[])(t_machine *) = {standard_state, mod_state, conv_state};
	t_machine			*machine;

	machine = init_machine(str, aptr, fd);
	while (machine->state != E_END)
		machine->input += state_function[machine->state](machine);
	machine->output = strnjoin(machine->output, machine->buffer, machine->index + 1);
	write(fd, machine->output, machine->nbof_buffer * BUFFER_SIZE + machine->index);
	free(machine->output);
	free(machine);
	return (EXIT_SUCCESS);
}

/*

// standard



// mod

	input_offset = 0;
	if (flag)
		input_offset = add_flag
	else
		state = converter
	return (input_offset);

// converter
	
	function = {conv_s, conv_d, conv_c, ...};

	string = function[](va_list, flags)
	add_to_buffer(string)
	free(string)

// conv_d

	return (conv_numeric(nb, flags, itoa))

// conv_numeric (nb, flags, char *(*function)(long))

	apply_flags()
	function(nb)
	
*/

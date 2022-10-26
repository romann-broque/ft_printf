/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 12:29:07 by rbroque          ###   ########.fr       */
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

size_t	fill_unknown(t_machine *machine)
{
	const char	option_char = OPTION_CHAR;
	size_t		offset;

	offset = 0;
	if (machine->input[0] != '\0' && machine->input[1] != '\0')
	{
		cpy_data(machine, (char *)(&option_char), sizeof(char));
		if (machine->input[2] != '\0')
			cpy_data(machine, machine->input, sizeof(char));
		++offset;
	}
	return (offset);
}

static size_t	conv_state(t_machine *machine)
{
	static void		(*fill_arg[NBOF_OPTIONS])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};
	const char		curr_c = *machine->input;
	ssize_t			option_index;
	size_t			input_offset;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
	{
		fill_arg[option_index](machine);
		input_offset = 1;
	}
	else
		input_offset = fill_unknown(machine);
	machine->flags = NO_FLAG;
	machine->width = 0;
	machine->state = E_STANDARD;
	return (input_offset);
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

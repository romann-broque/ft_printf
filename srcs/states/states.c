/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 11:36:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_state(t_machine *machine)
{
	size_t	offset;

	offset = apply_converter(machine);
	machine->arg->flags = NO_FLAG;
	machine->arg->width = 0;
	machine->arg->precision = UNSET_PRECISION;
	machine->state = E_STANDARD;
	return (offset);
}

size_t mod_state(t_machine *machine)
{
	const char	curr_c = *machine->input;
	size_t		input_offset;
	ssize_t		flag_index;

	input_offset = 0;
	flag_index = get_index(FLAGS, curr_c);
	if (flag_index > -1)
	{
		get_flag(&machine->arg->flags, flag_index);
		++input_offset; //input_offset+=ft_strlen(flag)
	}
	else
		machine->state = E_WIDTH;
	return (input_offset);
}

size_t	width_state(t_machine *machine)
{
	size_t	input_offset;

	input_offset = 0;
	if (ft_isdigit(*machine->input) != 0)
	{
		machine->arg->width = atol(machine->input); //code ft_atol function
		input_offset = get_nbsize(machine->arg->width, 10);
	}
	machine->state = E_PRECISION;
	return (input_offset);
}

size_t	precision_state(t_machine *machine)
{
	size_t	input_offset;
	char	*output;

	input_offset = 0;
	if (*machine->input == *PRECISION_CHAR)
	{
		++input_offset;
		machine->arg->precision = 0;
		if (ft_isdigit(machine->input[1]) != 0)
		{
			machine->arg->precision = atol(machine->input + 1); //code ft_atol function
			input_offset += get_nbsize(machine->arg->precision, 10);
		}
		else if (ft_strchr(OPTIONS, machine->input[1]) == NULL)
		{
			machine->arg->precision = 0;
			cpy_data(machine, OPTION_CHAR, sizeof(char));
			cpy_data(machine, PRECISION_CHAR, sizeof(char));
			output = integer_d(machine->arg->precision);
			cpy_data(machine, output, ft_strlen(output));
			free(output);
			machine->state = E_STANDARD;
		}
	}
	else
		machine->state = E_CONV;
	return (input_offset);
}

size_t	standard_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == END_CHAR)
		machine->state = E_END;
	else if (curr_c == *OPTION_CHAR)
		machine->state = E_MOD;
	else
		cpy_data(machine, (char *)machine->input, sizeof(char));
	return (1);
}

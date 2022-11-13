/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 12:13:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_state(t_machine *machine)
{
	size_t	offset;

	offset = apply_converter(machine);
	machine->arg->flags = NO_FLAG;
	machine->arg->width = 0;
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
	{
		if (ft_isdigit(curr_c) != 0)
		{
			machine->arg->width = atol(machine->input); //code ft_atol function
			input_offset += get_nbsize(machine->arg->width, 10);
		}
		machine->state = E_CONV;
	}
	return (input_offset);
}

size_t	standard_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == END_CHAR)
		machine->state = E_END;
	else if (curr_c == OPTION_CHAR)
		machine->state = E_MOD;
	else
		cpy_data(machine, (char *)machine->input, sizeof(char));
	return (1);
}

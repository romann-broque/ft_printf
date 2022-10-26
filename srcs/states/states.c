/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 16:03:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_state(t_machine *machine)
{
	static char		*(*fill_arg[NBOF_OPTIONS])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};
	const char		curr_c = *machine->input;
	char			*string;
	ssize_t			option_index;
	size_t			offset;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
		string = fill_arg[option_index](machine);
	else
		string = fill_unknown(machine);
	cpy_data(machine, string, ft_strlen(string));
	offset = (ft_strlen(string) > 0);
	free(string);
	machine->flags = NO_FLAG;
	machine->width = 0;
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
		get_flag(machine, flag_index);
		++input_offset;
	}
	else
		machine->state = E_CONV;
//	else if (ft_isdigit(curr_c) != 0)
//		get_width(machine);
	return (input_offset);
}

size_t	standard_state(t_machine *machine)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:10 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 22:55:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_state(t_machine *machine)
{
	size_t	offset;

	offset = apply_converter(machine);
	machine->arg->type = NO_TYPE;
	machine->state = E_STANDARD;
	return (offset);
}

size_t	standard_state(t_machine *machine)
{
	const char	curr_c = *machine->input;

	if (curr_c == END_CHAR)
		machine->state = E_END;
	else if (curr_c == *OPTION_CHAR)
		machine->state = E_CONV;
	else
		cpy_data(machine->output, (char *)machine->input, sizeof(char));
	return (1);
}

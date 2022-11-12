/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 10:28:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_type(ssize_t option_index)
{
	int	type;

	if (option_index > -1 && option_index < 8)
	{
		type = 0x01;
		type <<= option_index;
		if (type & INT_TYPE)
			return (INT_TYPE);
	}
	return (0);
}

size_t	apply_converter(t_machine *machine)
{
	static char		*(*converters[])() = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};
	const char		curr_c = *machine->input;
	char			*string;
	size_t			offset;
	ssize_t			option_index;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
		string = converters[option_index](machine->aptr, machine->flags, machine->width);
	else
		string = fill_unknown(machine);
	if (string != NULL)
		cpy_to_buffer(machine, string, get_type(option_index));
	offset = (curr_c != '\0');
	free(string);
	return (offset);
}

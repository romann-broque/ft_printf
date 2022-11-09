/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/09 13:41:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	cpy_to_buffer(machine, string);
	offset = (ft_strlen(string) > 0);
	free(string);
	return (offset);
}

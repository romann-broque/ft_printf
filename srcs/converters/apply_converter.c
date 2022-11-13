/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 10:14:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	get_type(ssize_t option_index)
{
	t_type	type;

	type = 0;
	if (option_index > -1)
	{
		type = 0x01;
		type <<= option_index;
	}
	return (type);
}

size_t	apply_converter(t_machine *machine)
{
	static char		*(*converter_type[])(t_type, va_list, t_flag *, size_t) = {
		character_conv,
		nb_conv};
	const char		curr_c = *machine->input;
	char			*string;
	t_type			type;
	ssize_t			option_index;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
	{
		type = get_type(option_index);
		string = converter_type[!(type & CHAR_TYPE)](type, machine->aptr, &machine->flags, machine->width);
	}
	else
		string = fill_unknown(machine);
	if (string != NULL)
		cpy_data(machine, string, ft_strlen(string));
	free(string);
	return (curr_c != '\0');
}

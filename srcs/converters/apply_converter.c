/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 15:06:09 by rbroque          ###   ########.fr       */
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
	static char		*(*converter_type[])(t_arg *arg) = {
		character_type,
		nb_type};
	const char		curr_c = *machine->input;
	char			*string;
	ssize_t			option_index;

	option_index = get_index(OPTIONS, curr_c);
	if (option_index > -1)
	{
		machine->arg->type = get_type(option_index);
		string = converter_type[!(machine->arg->type & CHAR_TYPE)](machine->arg);
	}
	else
		string = fill_unknown(machine);
	if (string != NULL)
		cpy_to_buffer(machine, string);
	free(string);
	return (curr_c != '\0');
}

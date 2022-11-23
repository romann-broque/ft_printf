/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:55:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 14:16:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void cpy_whitespaces_in_buff(t_machine *machine, char *width_part)
{
	if (width_part != NULL && *width_part != '\0')
		cpy_data(machine->output, width_part, ft_strlen(width_part));
}

static char get_width_unit(t_flag flags, t_type type)
{
	if (flags & ZERO_FLAG && !(flags & MINUS_FLAG) && type & NB_TYPE)
		return (WIDTH_UNIT[1]);
	return (WIDTH_UNIT[0]); 
}

void	cpy_to_buffer(t_machine *machine, char *string)
{
	const size_t	size = ft_strlen(string)
		+ (*string == '\0' && machine->arg->type & CHARACTER_TYPE);
	char			*width_part;
	char			width_unit;
	t_arg			*arg;

	arg = machine->arg;	
	arg->width = reduce_size(arg->width, size);
	width_unit = get_width_unit(arg->flags, arg->type);
	width_part = strset(width_unit, arg->width);
	if (arg->flags & MINUS_FLAG)
	{
		cpy_data(machine->output, string, size);
		cpy_whitespaces_in_buff(machine, width_part);
	}
	else
	{
		cpy_whitespaces_in_buff(machine, width_part);
		cpy_data(machine->output, string, size);
	}
	free(width_part);
}

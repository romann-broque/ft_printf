/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 21:23:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void cpy_whitespaces_in_buff(t_machine *machine, char *width_part, t_type type)
{
	if (type & NB_TYPE)
	{
		if (width_part != NULL && *width_part != '\0')
			cpy_data(machine, width_part, ft_strlen(width_part));
	}
}

static char get_width_unit(t_flag flags, t_type type)
{
	if (flags & ZERO_FLAG && !(flags & MINUS_FLAG) && type & NB_TYPE)
		return (WIDTH_UNIT[1]);
	return (WIDTH_UNIT[0]); 
}

void	cpy_to_buffer(t_machine *machine, char *string)
{
	const size_t	size = ft_strlen(string);
	char			*width_part;
	char			width_unit;
	t_arg			*arg;

	arg = machine->arg;	
	arg->width = reduce_size(arg->width, string);
	width_unit = get_width_unit(arg->flags, arg->type);
	width_part = strset(width_unit, arg->width);
	if (arg->flags & MINUS_FLAG)
	{
		cpy_data(machine, string, size);
		cpy_whitespaces_in_buff(machine, width_part, arg->type);
	}
	else
	{
		cpy_whitespaces_in_buff(machine, width_part, arg->type);
		cpy_data(machine, string, size);
	}
	free(width_part);
}

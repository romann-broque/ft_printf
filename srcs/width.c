/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:09 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 15:55:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 static size_t	reduce_width(size_t width, char *str)
{
	const size_t len = ft_strlen(str);

	if (width <= len)
		width = 0;
	else
		width -= len;
	return (width);
}

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
	char	*width_part;
	char	width_unit;
	t_arg	*arg;

	arg = machine->arg;	
	arg->width = reduce_width(arg->width, string);
	width_unit = get_width_unit(arg->flags, arg->type);
	width_part = strset(width_unit, arg->width);
	if (arg->flags & MINUS_FLAG)
	{
		cpy_data(machine, string, ft_strlen(string));
		cpy_whitespaces_in_buff(machine, width_part, arg->type);
	}
	else
	{
		cpy_whitespaces_in_buff(machine, width_part, arg->type);
		cpy_data(machine, string, ft_strlen(string));
	}
	free(width_part);
}

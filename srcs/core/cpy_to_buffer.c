/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:55:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/26 15:59:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
   static void cpy_whitespaces_in_buff(t_machine *machine, char *width_part)
   {
   if (width_part != NULL && *width_part != '\0')
   cpy_data(machine->output, width_part, ft_strlen(width_part));
   }
 */
static char get_width_unit(t_arg *arg, t_type type)
{
	if (arg->precision == UNSET_PRECISION && arg->flags & ZERO_FLAG && !(arg->flags & MINUS_FLAG) && type & NB_TYPE)
		return (WIDTH_UNIT[1]);
	return (WIDTH_UNIT[0]); 
}

void	cpy_to_buffer(t_machine *machine, char *string)
{
	size_t	size;
	//	char	*width_part;
	//	char	width_unit;
	t_arg	*arg;

	size = 0;
	arg = machine->arg;
	if (string != NULL)
		size = ft_strlen(string) + (*string == '\0' && arg->type & CHARACTER_TYPE);
	cpy_data(machine->output, string, size);
	/*
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
	 */
}

void	add_width(char **output, t_arg *arg)
{
	size_t	size;
	char	*width_part;
	char	*tmp;
	char	width_unit;

	size = 0;
	arg->width = reduce_size(arg->width, arg->size);
	width_unit = get_width_unit(arg, arg->type);
	width_part = strset(width_unit, arg->width);
	if (width_part != NULL && *width_part != '\0')
	{
		if (arg->flags & MINUS_FLAG)
		{
			*output = add_str(*output, width_part, arg->width);
			free(width_part);
		}
		else
		{
			tmp = *output;
			*output = add_str(width_part, *output, ft_strlen(*output));
			free(tmp);
		}
	}
	else
		free(width_part);
}

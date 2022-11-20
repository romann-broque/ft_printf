/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_truct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:55:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/20 15:14:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg		*init_arg(t_type type, va_list aptr)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (new != NULL)
	{
		va_copy(new->aptr, aptr);
		new->type = type;
		new->flags = NO_FLAG;
		new->width = 0;
		new->precision = UNSET_PRECISION;
	}
	return (new);
}

t_output	*init_output(void);
{
	t_arg	*new;

	new = (t_option *)malloc(sizeof(t_option));
	if (new != NULL)
	{
		ft_bzero(new->buffer, BUFFER_SIZE + 1);
		new->index = 0;
		new->nbof_buffer = 0;
		new->final_str = NULL;
	}
	return (new);
}

t_machine	*init_machine(const char *str, va_list aptr, int fd)
{
	t_machine	*new;

	new = (t_machine *)malloc(sizeof(t_machine));
	if (new != NULL)
	{
		new->input = str;
		new->output = init_output();
		new->arg = init_arg(NO_TYPE, aptr);
		new->fd = fd;
		new->state = E_STANDARD;
	}
	return (new);
}

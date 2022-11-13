/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:04:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 12:07:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*init_arg(t_type type, va_list aptr, t_flag flags, size_t width)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (new != NULL)
	{
		va_copy(new->aptr, aptr);
		new->type = type;
		new->flags = flags;
		new->width = width;
	}
	return (new);
}

t_machine	*init_machine(const char *str, va_list aptr, int fd)
{
	t_machine	*machine;

	machine = (t_machine *)malloc(sizeof(t_machine));
	if (machine != NULL)
	{
		machine->input = (char *)str;
		machine->output = NULL;
		machine->arg = init_arg(0, aptr, NO_FLAG, 0);
		ft_bzero(machine->buffer, BUFFER_SIZE);
		machine->nbof_buffer = 0;
		machine->index = 0;
		machine->fd = fd;
		machine->state = E_STANDARD;
	}
	return (machine);
}

void	free_machine(t_machine *machine)
{
	free(machine->output);
	free(machine->arg);
	free(machine);
}

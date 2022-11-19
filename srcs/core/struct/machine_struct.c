/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:04:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/19 13:59:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*init_arg(t_type type, va_list aptr)
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

static t_output	*init_output(void)
{
	t_output	*new;

	new = (t_output *)malloc(sizeof(t_output));
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
	t_machine	*machine;

	machine = (t_machine *)malloc(sizeof(t_machine));
	if (machine != NULL)
	{
		machine->input = (char *)str;
		machine->arg = init_arg(0, aptr);
		machine->output = init_output();
		machine->fd = fd;
		machine->state = E_STANDARD;
	}
	return (machine);
}

void	free_machine(t_machine *machine)
{
	free(machine->output->final_str);
	free(machine->output);
	free(machine->arg);
	free(machine);
}

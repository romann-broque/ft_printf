/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:55:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:22:41 by rbroque          ###   ########.fr       */
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
	}
	return (new);
}

t_output	*init_output(void)
{
	t_output	*new;

	new = (t_output *)malloc(sizeof(t_output));
	if (new != NULL)
	{
		ft_bzero(new->buffer, BUFFER_SIZE + 1);
		new->index = 0;
		new->total_size = 0;
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

void	free_machine(t_machine *machine)
{
	if (machine != NULL)
	{
		free(machine->arg);
		if (machine->output != NULL)
			free(machine->output->final_str);
		free(machine->output);
	}
	free(machine);
}

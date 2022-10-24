/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:04:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/24 14:45:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_machine	*init_machine(const char *str, va_list aptr, int fd)
{
	t_machine	*machine;

	machine = (t_machine *)malloc(sizeof(t_machine));
	if (machine != NULL)
	{
		machine->input = (char *)str;
		machine->aptr = aptr;
		ft_bzero(machine->buffer, BUFFER_SIZE);
		ft_bzero(machine->rest, BUFFER_SIZE);
		machine->nbof_buffer = 0;
		machine->index = 0;
		machine->width = 0;
		machine->fd = fd;
		machine->flags = NO_FLAG;
		machine->state = E_IDLE;
	}
	return (machine);
}

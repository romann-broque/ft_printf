/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:04:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/19 17:42:07 by rbroque          ###   ########.fr       */
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
		machine->fd = fd;
		machine->width = 0;
		machine->flags = NO_FLAG;
		machine->state = E_IDLE;
	}
	return (machine);
}

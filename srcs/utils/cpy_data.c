/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:46:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 15:04:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_new_buffer(t_machine *machine)
{
	machine->output = ft_strnjoin(machine->output, machine->buffer, BUFFER_SIZE);
	++machine->nbof_buffer;
	ft_bzero(machine->buffer, BUFFER_SIZE);
}

static void	fill_buffer(t_machine *machine, void *data, size_t *data_index)
{
	ft_memcpy(machine->buffer + machine->index, data + *data_index, BUFFER_SIZE - machine->index);
	*data_index += BUFFER_SIZE - machine->index;
	build_new_buffer(machine);
}

void	cpy_data(t_machine *machine, void *data, size_t n)
{
	size_t	data_index;

	data_index = 0;
	if (machine->index + n >= BUFFER_SIZE)
	{
		fill_buffer(machine, data, &data_index);
		machine->index = 0;
		n -= data_index;
	}
	while (machine->index + n >= BUFFER_SIZE)
	{
		fill_buffer(machine, data, &data_index);
		n -= BUFFER_SIZE;
	}
	ft_memcpy(machine->buffer + machine->index, data + data_index, n);
	machine->index += n;
}

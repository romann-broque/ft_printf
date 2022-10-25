/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 15:34:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	get_index(const char *str, const char c)
{
	ssize_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	if (str[index] == '\0' && c != '\0')
		index = -1;
	return (index);
}

void	cpy_data(t_machine *machine, void *data, size_t n)
{
	size_t	data_index;

	data_index = 0;
	if (machine->index + n >= BUFFER_SIZE)
	{
		ft_memcpy(machine->buffer + machine->index, data, BUFFER_SIZE - machine->index);
		data_index = BUFFER_SIZE - machine->index;
		machine->output = strnjoin(machine->output, machine->buffer, BUFFER_SIZE);
		++machine->nbof_buffer;
		ft_bzero(machine->buffer, BUFFER_SIZE);
		machine->index = 0;
		n -= data_index;
	}
	while (machine->index + n >= BUFFER_SIZE)
	{
		ft_memcpy(machine->buffer, data + data_index, BUFFER_SIZE);
		data_index += BUFFER_SIZE;
		machine->output = strnjoin(machine->output, machine->buffer, BUFFER_SIZE);
		++machine->nbof_buffer;
		ft_bzero(machine->buffer, BUFFER_SIZE);
		n -= BUFFER_SIZE;
	}
	ft_memcpy(machine->buffer + machine->index, data + data_index, n);
	machine->index += n;
}

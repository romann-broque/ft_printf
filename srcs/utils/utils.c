/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/09 01:17:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_new_buffer(t_machine *machine)
{
	machine->output = strnjoin(machine->output, machine->buffer, BUFFER_SIZE);
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

ssize_t	get_index(const char *str, const char c)
{
	ssize_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	if (str[index] == '\0')
		index = -1;
	return (index);
}

char	*to_string(const char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}

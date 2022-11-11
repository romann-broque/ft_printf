/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:46:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/11 23:15:35 by rbroque          ###   ########.fr       */
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

static size_t	reduce_width(size_t width, char *str)
{
	const size_t len = ft_strlen(str);

	if (width <= len)
		width = 0;
	else
		width -= len;
	return (width);
}

static void cpy_whitespaces_in_buff(t_machine *machine, char *width_part, int type, char *str)
{
	if (type & INT_TYPE)
	{
		if (width_part != NULL && *width_part != '\0')
			cpy_data(machine, width_part, ft_strlen(width_part));
		else if (machine->flags & SPACE_FLAG
			&& *str != '+' && *str != '-')
			cpy_data(machine, SPACE_PAT, ft_strlen(SPACE_PAT));
	}
}

void	cpy_to_buffer(t_machine *machine, char *string, int type)
{
	char	*width_part;

	machine->width = reduce_width(machine->width, string);
	width_part = strset(*WIDTH_UNIT, machine->width);
	if (machine->flags & MINUS_FLAG && !(machine->flags & SPACE_FLAG))
	{
		cpy_data(machine, string, ft_strlen(string));
		cpy_whitespaces_in_buff(machine, width_part, type, string);
	}
	else
	{
		cpy_whitespaces_in_buff(machine, width_part, type, string);
		cpy_data(machine, string, ft_strlen(string));
	}
	free(width_part);
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

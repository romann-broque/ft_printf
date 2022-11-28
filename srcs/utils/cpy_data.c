/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:46:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:20:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_new_buffer(t_output *output)
{
	output->final_str = add_str(output->final_str, output->buffer, BUFFER_SIZE);
	output->total_size += BUFFER_SIZE;
	ft_bzero(output->buffer, BUFFER_SIZE);
}

static void	fill_buffer(t_output *output, void *data, size_t *data_index)
{
	ft_memcpy(output->buffer + output->index, data + *data_index,
			BUFFER_SIZE - output->index);
	*data_index += BUFFER_SIZE - output->index;
	build_new_buffer(output);
}

void	cpy_data(t_output *output, void *data, size_t n)
{
	size_t	data_index;

	data_index = 0;

	if (output->index + n > BUFFER_SIZE)
	{
		fill_buffer(output, data, &data_index);
		output->index = 0;
		if (n > data_index)
			n -= data_index;
	}
	while (output->index + n > BUFFER_SIZE)
	{
		fill_buffer(output, data, &data_index);
		if (n > BUFFER_SIZE)
			n -= BUFFER_SIZE;
	}
	ft_memcpy(output->buffer + output->index, data + data_index, n);
	output->index += n;
}

void	cpy_to_buffer(t_machine *machine, char *string)
{
	const size_t	size = ft_strlen(string)
					+ (*string == '\0' && machine->arg->type & CHARACTER_TYPE);

	cpy_data(machine->output, string, size);
}

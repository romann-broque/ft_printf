/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/24 15:31:05 by rbroque          ###   ########.fr       */
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
	if (machine->index + n < BUFFER_SIZE)
		ft_memcpy(machine->buffer + machine->index, data, n);
	else
		ft_memcpy(machine->rest, data, n);
	machine->index += n;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:55:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 12:03:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cpy_to_buffer(t_machine *machine, char *string)
{
	const size_t	size = ft_strlen(string)
					+ (*string == '\0' && machine->arg->type & CHARACTER_TYPE);

	cpy_data(machine->output, string, size);
}

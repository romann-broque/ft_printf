/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/24 16:29:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_machine *machine)
{
	const char	*null_def = NULL_DEF;
	char		*str;

	str = va_arg(machine->aptr, char *);
	if (str == NULL)
		cpy_data(machine, (char *)null_def, ft_strlen(null_def));
	else
		cpy_data(machine, str, ft_strlen(str));
}

void	character(t_machine *machine)
{
	const int	c = va_arg(machine->aptr, int);

	cpy_data(machine, (char *)&c, sizeof(char));
}

void	percentage(t_machine *machine)
{
	machine->buffer[machine->index] = '%';
	++(machine->index);
}

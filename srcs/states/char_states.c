/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 18:29:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_machine *machine)
{
	char		*str;

	str = va_arg(machine->aptr, char *);
	if (str == NULL)
		str = NULL_DEF;
	cpy_data(machine, str, ft_strlen(str));
}

void	character(t_machine *machine)
{
	const int	c = va_arg(machine->aptr, int);

	cpy_data(machine, (char *)&c, sizeof(char));
}

void	percentage(t_machine *machine)
{
	const int	c = '%';

	cpy_data(machine, (char *)&c, sizeof(char));
}

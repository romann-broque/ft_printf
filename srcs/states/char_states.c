/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 16:39:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_machine *machine)
{
	char	*str;

	str = va_arg(machine->aptr, char *);
	if (str == NULL)
		ft_putstr_fd(NULL_DEF, machine->fd);
	else
		ft_putstr_fd(str, machine->fd);
}

void	character(t_machine *machine)
{
	const int	c = va_arg(machine->aptr, int);

	ft_putchar_fd(c, machine->fd);
}

void	percentage(t_machine *machine)
{
	ft_putchar_fd('%', machine->fd);
}

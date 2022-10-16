/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:47:25 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 23:59:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_machine *machine)
{
	char	*str;

	str = va_arg(machine->aptr, char *);
	ft_putstr_fd(str, machine->fd);
}

void	character(t_machine *machine)
{
	const int	c = va_arg(machine->aptr, int);

	ft_putchar_fd(c, machine->fd);
}

void	low_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);

	ft_puthex_fd(LOW_HEX, nb, machine->fd);
}

void	up_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);

	ft_puthex_fd(UP_HEX, nb, machine->fd);
}

void	address(t_machine *machine)
{
	const unsigned long	address = va_arg(machine->aptr, unsigned long);

	if (address == 0)
		ft_putstr_fd(NIL_DEF, machine->fd);
	else
	{
		ft_putstr_fd(PRE_HEX, machine->fd);
		ft_putlhex_fd(LOW_HEX, address, machine->fd);
	}
}

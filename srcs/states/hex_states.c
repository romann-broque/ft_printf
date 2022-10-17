/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 16:38:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/19 17:28:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer(t_machine *machine)
{
	const int	nb = va_arg(machine->aptr, int);

	if (nb >= 0)
	{
		if (machine->flags & PLUS_FLAG)
			ft_putchar_fd('+', machine->fd);
		else if (machine->width == 0 && machine->flags & SPACE_FLAG)
			ft_putchar_fd(' ', machine->fd);
	}
	ft_putnbr_fd(nb, machine->fd);
}

void	u_integer(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);

	ft_putunbr_fd(nb, machine->fd);
}

void	integer_ten(t_machine *machine)
{
	integer(machine);
}

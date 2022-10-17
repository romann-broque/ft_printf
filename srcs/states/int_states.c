/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 16:39:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer(t_machine *machine)
{
	const int	nb = va_arg(machine->aptr, int);

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

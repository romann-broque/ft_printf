/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 17:19:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	low_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);
	const char			*prefix_hex = PREFIX_HEX;

	if (machine->flags & PREFIX_FLAG && nb > 0)
		cpy_data(machine, (char *)prefix_hex, ft_strlen(prefix_hex));
	fill_hex(LOW_HEX, nb, machine);
}

void	up_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);
	const char			*prefix_hex = PREFIX_HEX;

	if (machine->flags & PREFIX_FLAG && nb > 0)
		cpy_data(machine, (char *)prefix_hex, ft_strlen(prefix_hex));
	fill_hex(UP_HEX, nb, machine);
}

void	address(t_machine *machine)
{
	const unsigned long	address = va_arg(machine->aptr, unsigned long);
	const char			*pre_hex = PRE_HEX;
	const char			*nil_def = NIL_DEF;

	if (address == 0)
		cpy_data(machine, (char *)nil_def, ft_strlen(nil_def));
	else
	{
		cpy_data(machine, (char *)pre_hex, ft_strlen(pre_hex));
		fill_lhex(LOW_HEX, address, machine);
	}
}

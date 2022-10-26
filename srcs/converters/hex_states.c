/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 15:44:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);
	const char			*prefix_hex = PREFIX_HEX;

	if (machine->flags & PREFIX_FLAG && nb > 0)
		cpy_data(machine, (char *)prefix_hex, ft_strlen(prefix_hex));
	fill_hex(LOW_HEX, nb, machine);
	return (NULL);
}

char	*up_hex(t_machine *machine)
{
	return (low_hex(machine));
}

char	*address(t_machine *machine)
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
	return (NULL);
}

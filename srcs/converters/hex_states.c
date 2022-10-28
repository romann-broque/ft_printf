/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/28 17:21:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);
	char				*nb_base;
	char				*output;

	output = NULL;
	if (machine->flags & PREFIX_FLAG && nb > 0)
		output = ft_strdup(PREFIX_HEX);
	nb_base = itoa_base(nb, HEX);
	output = strnjoin(output, nb_base, ft_strlen(nb_base));
	free(nb_base);
	return (output);
}

char	*up_hex(t_machine *machine)
{
	return (toupper_str(low_hex(machine)));
}

char	*address(t_machine *machine)
{
	const unsigned long	address = va_arg(machine->aptr, unsigned long);
	char				*address_hex;
	char				*output;

	output = NULL;
	if (address == 0)
		output = ft_strdup(NIL_DEF);
	else
	{
		if (machine->flags & SPACE_FLAG)
			output = ft_strdup(WIDTH_UNIT);
		output = strnjoin(output, PRE_HEX, ft_strlen(PRE_HEX));
		address_hex = itoa_base(address, HEX);
		output = strnjoin(output, address_hex, ft_strlen(address_hex));
		free(address_hex);
	}
	return (output);
}

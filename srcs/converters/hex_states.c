/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 13:10:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(unsigned long nb)
{
	return (itoa_base(nb, HEX));
}

char	*up_hex(unsigned long nb)
{
	return (toupper_str(low_hex(nb)));
}

char	*address(unsigned long address)
{
	char				*output;

	output = NULL;
	if (address == 0)
	{
		output = ft_strdup(NIL_DEF);
//		remove_flag(flags, SPACE_FLAG);
	}
	else
	{
		output = low_hex(address);
	//	output = ft_strnjoin(output, PREFIX_HEX, ft_strlen(PREFIX_HEX));
	//	address_hex = itoa_base(address, HEX);
	///	output = ft_strnjoin(output, address_hex, ft_strlen(address_hex));
	//	free(address_hex);
	}
	return (output);
}

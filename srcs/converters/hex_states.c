/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 14:11:36 by rbroque          ###   ########.fr       */
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
		output = ft_strdup(NIL_DEF);
	else
		output = low_hex(address);
	return (output);
}

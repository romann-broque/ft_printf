/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 15:28:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(va_list aptr)
{
	const unsigned int	nb = va_arg(aptr, unsigned int);
	char				*output;

	output = NULL;
	if (nb == 0)
		output = ft_strdup(NULL_DEF);
	else
		output = itoa_base(nb, HEX);
	return (output);
}

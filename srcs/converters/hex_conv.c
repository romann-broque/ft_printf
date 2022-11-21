/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 17:12:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(va_list aptr)
{
	const unsigned int	nb = va_arg(aptr, unsigned int);

	return (itoa_base(nb, HEX));
}

char	*up_hex(va_list aptr)
{
	return (toupper_str(low_hex(aptr)));
}

char	*address(va_list aptr)
{
	const unsigned int	nb = va_arg(aptr, unsigned int);
	char				*output;
	char				*nb_str;

	if (nb == 0)
		output = ft_strdup(NIL_DEF);
	else
	{
		output = ft_strdup(PREFIX_HEX);
		nb_str = itoa_base(nb, HEX);
		output = add_str(output, nb_str, ft_strlen(nb_str));
		free(nb_str);
	}
	return (output);
}

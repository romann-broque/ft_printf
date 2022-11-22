/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:26:06 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/22 18:53:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*low_hex(unsigned int nb)
{
	return (itoa_base(nb, HEX));
}

char	*up_hex(unsigned int nb)
{
	return (toupper_str(low_hex(nb)));
}

char	*address(void *address)
{
	char	*output;
	char	*nb_str;

	if (address == NULL)
		output = ft_strdup(NIL_DEF);
	else
	{
		output = ft_strdup(PREFIX_HEX);
		nb_str = itoa_base((unsigned long)address, HEX);
		output = add_str(output, nb_str, ft_strlen(nb_str));
		free(nb_str);
	}
	return (output);
}

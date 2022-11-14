/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:00:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 12:18:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_type(t_arg *arg)
{
	const unsigned long	nb = va_arg(arg->aptr, unsigned long);
	char				*conv_out;
	char				*output;

	output = NULL;
	if (nb != 0 || arg->precision != 0)
	{
		if (arg->type & HEX_TYPE)
			conv_out = hex_type(arg, nb);
		else
			conv_out = u_integer(nb);
		output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
		free(conv_out);
	}
	return (output);
}

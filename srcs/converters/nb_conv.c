/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:57:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 16:44:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer_d(va_list aptr)
{
	const int	nb = va_arg(aptr, int);
	char		*nb_str;
	char		*output;

	output = NULL;
	if (nb < 0)
		output = ft_strdup(MINUS_SIGN);
	nb_str = itoa_base(get_abs(nb), DEC);
	output = add_str(output, nb_str, ft_strlen(nb_str));
	free(nb_str);
	return (output);
}

char	*integer_i(va_list aptr)
{
	return (integer_d(aptr));
}

char	*u_integer(va_list aptr)
{
	const unsigned int	nb = va_arg(aptr, unsigned int);
	char				*nb_str;
	char				*output;

	output = NULL;
	nb_str = itoa_base(nb, DEC);
	output = add_str(output, nb_str, ft_strlen(nb_str));
	free(nb_str);
	return (output);
}
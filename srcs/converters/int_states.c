/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 14:25:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer_d(int nb)
{
	char		*nb_output;
	char		*output;

	output = NULL;
	if (nb < 0)
		output = ft_strdup(MINUS_SIGN);
	nb_output = itoa_base(get_abs(nb), DEC);
	output = ft_strnjoin(output, nb_output, ft_strlen(nb_output));
	free(nb_output);
	return (output);
}

char	*u_integer(va_list aptr)
{
	const unsigned int	nb = va_arg(aptr, unsigned int);
	char				*nb_output;
	char				*output;

	output = NULL;
	nb_output = itoa_base(nb, DEC);
	output = ft_strnjoin(output, nb_output, ft_strlen(nb_output));
	free(nb_output);
	return (output);
}

char	*integer_i(int nb)
{
	return (integer_d(nb));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 17:59:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer(va_list aptr, int flags)
{
	const int	nb = va_arg(aptr, int);
	char		*nb_output;
	char		*output;

	output = NULL;
	if (nb >= 0)
	{
		if (flags & PLUS_FLAG)
			output = ft_strdup(PLUS_SIGN);
//		else if (machine->width == 0 && machine->flags & SPACE_FLAG)
//			output = ft_strdup(WIDTH_UNIT);
	}
	else
			output = ft_strdup(MINUS_SIGN);
	nb_output = itoa_base(get_abs(nb), DEC);
	output = strnjoin(output, nb_output, ft_strlen(nb_output));
	free(nb_output);
	return (output);
}

char	*u_integer(va_list aptr, int flags)
{
//	const unsigned int	nb = va_arg(aptr, unsigned int);

//	fill_unbr(nb, machine);
	(void)aptr;
	(void)flags;
	return (NULL);
}

char	*integer_ten(va_list aptr, int flags)
{
	return (integer(aptr, flags));
}

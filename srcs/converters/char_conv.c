/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:31:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/26 17:20:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	reduce_to_precision(size_t len, ssize_t precision)
{
	size_t	final_len;

	final_len = len;
	if (precision != UNSET_PRECISION && final_len > (size_t)precision)
			final_len = precision;
	return (final_len);
}

char	*character(va_list aptr)
{
	const int	c = va_arg(aptr, int);

	return (to_string(c));
}

char	*string(va_list aptr, ssize_t precision)
{
	const char	*str = va_arg(aptr, char *);
	size_t		len;
	size_t		final_len;

	if (str == NULL)
	{
		len = ft_strlen(NULL_DEF);
		final_len = reduce_to_precision(len, precision);
		if (final_len < len)
			final_len = 0;
		return (ft_strndup(NULL_DEF, final_len));
	}
	final_len = ft_strlen(str);
	if (precision != UNSET_PRECISION)
		final_len = reduce_to_precision(final_len, precision);
	return (ft_strndup(str, final_len));
}

char	*percentage(void)
{
	return (to_string(*OPTION_CHAR));
}

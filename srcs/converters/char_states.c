/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 10:31:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string(va_list aptr, ssize_t precision)
{
	char	*str;
	size_t	len;
	size_t	size;

	str = va_arg(aptr, char *);
	if (str == NULL)
		str = NULL_DEF;
	len = ft_strlen(str);
	if (precision != UNSET_PRECISION)
		size = get_min(len, precision);
	else
		size = len;
	return (ft_strndup(str, size));
}

char	*character(va_list aptr)
{
	const char	c = va_arg(aptr, int);

	return (to_string(c));
}

char	*percentage(void)
{
	return (ft_strdup(OPTION_CHAR));
}

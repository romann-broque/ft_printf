/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 22:44:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string(va_list aptr)
{
	char		*str;

	str = va_arg(aptr, char *);
	if (str == NULL)
		str = NULL_DEF;
	return (ft_strdup(str));
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

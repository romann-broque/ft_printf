/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:31:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:42:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*character(va_list aptr)
{
	const int	c = va_arg(aptr, int);

	return (to_string(c));
}

char	*string(va_list aptr)
{
	char	*str;

	str = va_arg(aptr, char *);
	if (str == NULL)
		return (ft_strdup(NULL_DEF));
	else
		return (ft_strdup(str));
}

char	*percentage(void)
{
	return (to_string(*OPTION_CHAR));
}

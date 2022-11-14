/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 20:12:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	get_index(const char *str, const char c)
{
	ssize_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	if (str[index] == '\0')
		index = -1;
	return (index);
}

char	*to_string(const char c)
{
	char	*str;

	str = (char *)malloc((2) * sizeof(char));
	if (str != NULL)
	{
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}

size_t	reduce_size(size_t width, char *str)
{
	const size_t len = ft_strlen(str);

	if (width <= len)
		width = 0;
	else
		width -= len;
	return (width);
}


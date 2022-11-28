/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 22:54:31 by rbroque          ###   ########.fr       */
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

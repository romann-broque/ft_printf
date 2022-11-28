/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:18:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *str, const size_t size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, str, size + 1);
	return (new);
}

char	*add_str(char *s1, const char *s2, const size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	len1 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1) + (*s1 == '\0');
	len2 = n;
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		ft_memcpy(new, (char *)s1, len1);
		ft_memcpy(new + len1, (char *)s2, len2);
		new[len1 + len2] = '\0';
	}
	free(s1);
	return (new);
}

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

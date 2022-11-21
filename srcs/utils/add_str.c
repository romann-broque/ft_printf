/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:25:12 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 15:01:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (s1 != NULL)
			ft_memcpy(new, (char *)s1, len1);
		ft_memcpy(new + len1, (char *)s2, len2);
		new[len1 + len2] = '\0';
	}
	free(s1);
	return (new);
}

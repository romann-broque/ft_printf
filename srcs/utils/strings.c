/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 09:55:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strset(int c, size_t n)
{
	char	*new;

	new = (char *)malloc((n + 1) * sizeof(char));
	if (new != NULL)
	{
		ft_memset(new, c, n);
		new[n] = '\0';
	}
	return (new);
}

char	*ft_strndup(const char *str, const size_t size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, str, size + 1);
	return (new);
}

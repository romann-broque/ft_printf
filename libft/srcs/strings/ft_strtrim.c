/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/22 15:08:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *str, size_t n)
{
	char	*new;

	new = (char *)malloc((n + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, str, n + 1);
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trim;

	if (s1 != NULL)
	{
		while (set != NULL && *s1 != '\0' && ft_strchr(set, *s1) != NULL)
			++s1;
		len = ft_strlen(s1);
		while (set != NULL && len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
			--len;
		trim = ft_strndup(s1, len);
	}
	else
		trim = NULL;
	return (trim);
}

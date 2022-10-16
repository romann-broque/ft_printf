/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:30:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/15 14:03:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	len1 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc((len1 + len2 + 1) + sizeof(char));
	if (new != NULL)
	{
		if (s1 != NULL)
			ft_strlcpy(new, (char *)s1, len1 + 1);
		ft_strlcpy(new + len1, (char *)s2, len2 + 1);
	}
	return (new);
}

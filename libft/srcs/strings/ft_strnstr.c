/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:43:28 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/12 15:01:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (little[j] != '\0'
			&& big[i + j] != '\0'
			&& little[j] == big[i + j])
			++j;
		if (little[j] == '\0')
			return ((char *)(big + i));
		if (big[i] == '\0')
			break ;
		++i;
	}
	return (NULL);
}

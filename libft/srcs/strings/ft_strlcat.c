/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:19:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/22 15:25:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_min_size(const size_t size1, const size_t size2)
{
	if (size1 < size2)
		return (size1);
	return (size2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	size_dest = ft_strlen(dst);
	const size_t	size_src = ft_strlen(src);
	const size_t	min_size = get_min_size(size_dest, dstsize);

	ft_strlcpy(dst + size_dest, src, dstsize - size_dest);
	return (min_size + size_src);
}

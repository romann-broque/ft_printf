/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/14 15:30:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	total_size = nmemb * size;
	void			*ptr;

	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_bzero(ptr, total_size);
	return (ptr);
}

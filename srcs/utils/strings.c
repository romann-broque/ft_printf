/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:23 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/09 14:22:23 by rbroque          ###   ########.fr       */
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

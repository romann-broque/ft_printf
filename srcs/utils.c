/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/13 17:20:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_index(const char *str, const char c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	return (index);
}

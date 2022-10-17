/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:18:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 21:00:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	get_index(const char *str, const char c)
{
	ssize_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		++index;
	if (str[index] == '\0' && c != '\0')
		index = -1;
	return (index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:59:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 18:44:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_precision(size_t precision, char *string)
{
	if (precision > INT_MAX)
		return (NULL);
	precision = reduce_size(precision, string);
	return (strset('0', precision));
}

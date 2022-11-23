/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:54:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 15:56:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_precision(ssize_t precision, char *string)
{
	if (precision > INT_MAX)
		return (NULL);
	if (precision == UNSET_PRECISION)
		precision = 0;
	precision = reduce_size(precision, ft_strlen(string));
	return (strset('0', precision));
}

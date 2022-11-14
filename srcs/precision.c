/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:59:57 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 10:38:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_precision(ssize_t precision, char *string)
{
	if (precision > INT_MAX)
		return (NULL);
	if (precision == UNSET_PRECISION)
		precision = 0;
	precision = reduce_size(precision, string);
	return (strset('0', precision));
}

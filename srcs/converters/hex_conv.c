/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 11:42:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_conv(t_arg *arg)
{
	static char		*(*converters[])() = {low_hex, up_hex, address};
	const ssize_t	type_index = ((arg->type > LOW_TYPE) + (arg->type > UP_TYPE));
	return (converters[type_index](arg));
}

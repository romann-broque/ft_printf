/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:00:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 21:07:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width)
{
	if (curr_type & HEX_TYPE)
		return (hex_conv(curr_type, aptr, flags, width));
	else
		return (u_integer(aptr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 21:07:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width)
{
	static char		*(*converters[])() = {low_hex, up_hex, address};
	ssize_t			type_index;

	type_index = get_index_from_type(curr_type, HEX_TYPE);
	return (converters[type_index](aptr, &flags, width));
}

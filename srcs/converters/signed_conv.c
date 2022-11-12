/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:56:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 20:50:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width)
{
	static char		*(*converters[])() = {integer_d, integer_i};
	ssize_t			type_index;

	type_index = get_index_from_type(curr_type, SIGNED_TYPE);
	return (converters[type_index](aptr, &flags, width));
}

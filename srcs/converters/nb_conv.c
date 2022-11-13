/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 10:20:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*nb_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width)
{
	static char		*(*converters[])(t_type, va_list, t_flag *, size_t) = {
		signed_conv,
		unsigned_conv};

	return (converters[!(curr_type & SIGNED_TYPE)](curr_type, aptr, flags, width));
}

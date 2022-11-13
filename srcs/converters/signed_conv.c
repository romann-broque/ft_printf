/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:56:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 12:36:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_conv(t_arg *arg)
{
	static char		*(*converters[])(va_list, t_flag) = {integer_d, integer_i};
	ssize_t			type_index;

	type_index = get_index_from_type(arg->type, SIGNED_TYPE);
	return (converters[type_index](arg->aptr, arg->flags));
}

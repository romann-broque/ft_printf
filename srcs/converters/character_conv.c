/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:51:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 21:22:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*character_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width)
{
	static char		*(*converters[])() = {character, string, percentage};
	size_t			type_index;

	type_index = get_index_from_type(curr_type, CHAR_TYPE);
	return (converters[type_index](aptr, flags, width));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:51:41 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 11:54:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*character_conv(t_arg *arg)
{
	static char		*(*converters[])() = {character, string, percentage};
	size_t			type_index;

	type_index = get_index_from_type(arg->type, CHAR_TYPE);
	return (converters[type_index](arg->aptr));
}

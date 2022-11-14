/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:39 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 10:31:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*character_type(t_arg *arg)
{
	static char		*(*converters[])() = {character, string, percentage};
	size_t			type_index;

	type_index = get_index_from_type(arg->type, CHAR_TYPE);
	return (converters[type_index](arg->aptr, arg->precision));
}

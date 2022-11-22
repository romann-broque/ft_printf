/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:58 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/22 18:57:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_type(t_arg *arg, unsigned long nb)
{
	static char		*(*converters[])() = {low_hex, up_hex, address};
	const ssize_t	type_index = ((arg->type > LOW_TYPE) + (arg->type > UP_TYPE));
	char			*conv_out;
	char			*output;

	output = NULL;
	if (nb == 0)
			remove_flag(&arg->flags, PREFIX_FLAG);
	else if (arg->type & ADDRESS_TYPE)
			add_flag(&arg->flags, PREFIX_FLAG);
	conv_out = converters[type_index](nb);
	output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
	free(conv_out);
	return (output);
}

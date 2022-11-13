/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:56:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 14:38:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_type(t_arg *arg)
{
	static char		*(*converters[])(int) = {integer_d, integer_i};
	const ssize_t	type_index = get_index_from_type(arg->type, SIGNED_TYPE);
	const int	nb = va_arg(arg->aptr, int);
	char			*conv_out;
	char			*output;

	output = NULL;
	if (nb >= 0)
	{
		if (arg->flags & PLUS_FLAG)
			output = ft_strdup(PLUS_SIGN);
		else if (arg->flags & SPACE_FLAG)
			output = ft_strdup(SPACE_PAT);
	}
	conv_out = converters[type_index](nb);
	output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
	free(conv_out);
	return (output);
}

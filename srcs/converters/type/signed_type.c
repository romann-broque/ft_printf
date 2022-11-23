/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:25 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 21:43:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_type(t_arg *arg)
{
	static char		*(*converters[])(int) = {integer_d, integer_i};
	const ssize_t	type_index = get_index_from_type(arg->type, SIGNED_TYPE) - 1;
	const int		nb = va_arg(arg->aptr, int);
	char			*conv_out;
	char			*output;
	char			*precision_part;

	output = NULL;
	if (nb != 0 || arg->precision != 0)
	{
		if (nb >= 0)
		{
			if (arg->flags & PLUS_FLAG)
				output = ft_strdup(PLUS_SIGN);
			else if (arg->flags & SPACE_FLAG)
				output = ft_strdup(SPACE_PAT);
		}
		else
				output = ft_strdup(MINUS_SIGN);
		conv_out = converters[type_index](nb);
		precision_part = get_precision(arg->precision, conv_out);
		output = ft_strnjoin(output, precision_part, ft_strlen(precision_part));
		output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
		add_width(&output, arg);
		free(precision_part);
		free(conv_out);
	}
	return (output);
}

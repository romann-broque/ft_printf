/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:25 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/24 15:45:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign(int nb, char **output, t_arg *arg)
{
	if (nb >= 0)
	{
		if (arg->flags & PLUS_FLAG)
			prefix_add(PLUS_SIGN, output);
		else if (arg->flags & SPACE_FLAG)
			prefix_add(SPACE_PAT, output);
	}
	else
		prefix_add(MINUS_SIGN, output);
}

void	add_beginning(int nb, char **output, t_arg *arg)
{
	if (arg->flags & ZERO_FLAG && !(arg->flags & MINUS_FLAG))
	{
		add_width(output, arg);
		add_sign(nb, output, arg);
	}
	else
	{
		add_sign(nb, output, arg);
		add_width(output, arg);
	}
}

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
		conv_out = converters[type_index](nb);
		precision_part = get_precision(arg->precision, conv_out);
		output = ft_strnjoin(output, precision_part, ft_strlen(precision_part));
		output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
		arg->size = ft_strlen(output) + ((arg->flags & PLUS_FLAG) || (nb < 0) || (arg->flags & SPACE_FLAG));
		free(precision_part);
		free(conv_out);
	}
	add_beginning(nb, &output, arg);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:32 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 15:20:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_type(t_arg *arg)
{
	static char		*(*converters[])(unsigned long) = {low_hex, up_hex, address};
	const ssize_t	type_index = ((arg->type > LOW_TYPE) + (arg->type > UP_TYPE));
	const unsigned long	nb = va_arg(arg->aptr, unsigned long);
	char			*conv_out;
	char			*output;

	output = NULL;
	if (arg->flags & SPACE_FLAG && !(arg->flags & PLUS_FLAG))
		output = ft_strnjoin(output, SPACE_PAT, ft_strlen(SPACE_PAT));
	if (nb > 0 && (arg->flags & PREFIX_FLAG || arg->type & ADDRESS_TYPE))
	{
		output = ft_strnjoin(output, PREFIX_HEX, ft_strlen(PREFIX_HEX));
		if (arg->type & UP_TYPE)
			output = toupper_str(output);
	}
	conv_out = converters[type_index](nb);
	output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
	free(conv_out);
	return (output);
}

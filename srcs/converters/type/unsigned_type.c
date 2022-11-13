/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:00:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 14:43:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_type(t_arg *arg)
{
	char			*conv_out;
	char			*output;

	output = NULL;
	if (arg->flags & PLUS_FLAG)
		output = ft_strdup(PLUS_SIGN);
	else if (arg->flags & SPACE_FLAG)
		output = ft_strdup(SPACE_PAT);
	if (arg->type & HEX_TYPE)
		conv_out = hex_type(arg);
	else
		conv_out = u_integer(arg->aptr);
	output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
	return (output);
}

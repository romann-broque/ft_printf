/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:35:26 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/23 16:00:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*nb_type(t_arg *arg)
{
	static char		*(*converters[])(t_arg *) = {
		signed_type,
		unsigned_type};
	const ssize_t	type_index = !(arg->type & SIGNED_TYPE);
	char			*conv_out;
	char			*output;

	output = NULL;
	conv_out = converters[type_index](arg);
	if (conv_out != NULL)
	{
		output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
		if (arg->flags & PREFIX_FLAG)
		{
			prefix_add(PREFIX_HEX, &output);
			if (arg->type & UP_TYPE)
				output = toupper_str(output);
		}	
		if ((arg->flags & SPACE_FLAG)
			&& !(arg->flags & PLUS_FLAG)
			&& (arg->type & HEX_TYPE))
			prefix_add(SPACE_PAT, &output);
	}
	free(conv_out);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 14:44:02 by rbroque          ###   ########.fr       */
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
	output = ft_strnjoin(output, conv_out, ft_strlen(conv_out));
	free(conv_out);
	return (output);
}

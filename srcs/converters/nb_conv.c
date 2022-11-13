/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 11:40:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*nb_conv(t_arg *arg)
{
	static char		*(*converters[])(t_arg *) = {
		signed_conv,
		unsigned_conv};

	return (converters[!(arg->type & SIGNED_TYPE)](arg));
}

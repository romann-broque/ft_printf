/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:00:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 11:41:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_conv(t_arg *arg)
{
	if (arg->type & HEX_TYPE)
		return (hex_conv(arg));
	else
		return (u_integer(arg->aptr));
}

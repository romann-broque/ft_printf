/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:04:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 17:49:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_abs(int nb)
{
	unsigned int	abs;

	if (nb < 0)
		abs = -nb;
	else
		abs = nb;
	return (abs);
}

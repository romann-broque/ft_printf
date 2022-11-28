/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:25:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:26:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_abs(int nb)
{
	unsigned int	abs;

	if (nb < 0)
		abs = -(unsigned int)nb;
	else
		abs = nb;
	return (abs);
}

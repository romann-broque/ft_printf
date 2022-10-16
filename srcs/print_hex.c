/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:10:56 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 20:29:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_fd(const unsigned long nb, int fd)
{
	if (nb > 0)
	{
		print_hex_fd(nb / 16, fd);
		ft_putchar_fd(HEX[nb % 16], fd);
	}
}

void	ft_puthex_fd(const unsigned long nb, int fd)
{
	print_hex_fd(nb, fd);
}


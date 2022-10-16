/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:10:56 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 23:35:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex_fd(const char *hbase, const unsigned int nb, int fd)
{
	if (nb != 0)
	{
		print_hex_fd(hbase, nb / 16, fd);
		ft_putchar_fd(hbase[nb % 16], fd);
	}
}

static void	print_lhex_fd(const char *hbase, const unsigned long nb, int fd)
{
	if (nb != 0)
	{
		print_lhex_fd(hbase, nb / 16, fd);
		ft_putchar_fd(hbase[nb % 16], fd);
	}
}

void	ft_puthex_fd(const char *hbase, const unsigned int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	print_hex_fd(hbase, nb, fd);
}

void	ft_putlhex_fd(const char *hbase, const unsigned long nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	print_lhex_fd(hbase, nb, fd);
}

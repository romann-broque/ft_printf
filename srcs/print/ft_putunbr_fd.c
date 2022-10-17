/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 15:13:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nb(unsigned int n, int fd)
{
	if (n > 0)
	{
		print_nb(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	print_nb(n, fd);
}

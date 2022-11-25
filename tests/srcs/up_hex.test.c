/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_hex.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:22:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 15:54:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%X";
	const unsigned int	nb = 247558;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test2(int fd1, int fd2)
{
	const char	*test_name = "test2: ";
	const char	*str = "%X";
	const unsigned int	nb = UINT_MAX;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test3(int fd1, int fd2)
{
	const char	*test_name = "test3: ";
	const char	*str = "%X";
	const unsigned int	nb = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test1_bonus(int fd1, int fd2)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "%#+X";
	const unsigned int	nb = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "%#    +X";
	const unsigned int	nb = 9134;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

void	up_hex_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, UP_HEX_TESTS);
	dprintf(fd2, UP_HEX_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1, fd2);
/*
*/
}

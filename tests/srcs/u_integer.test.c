/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:08:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 18:03:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%u";
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
	const char	*str = "%u";
	const unsigned int	nb = INT_MAX;

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
	const char	*str = "%u";
	const unsigned int	nb = UINT_MAX;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test4(int fd1, int fd2)
{
	const char	*test_name = "test4: ";
	const char	*str = "%u";
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
	const char	*str = "% u %    u";
	const unsigned int	nb1 = 3;
	const unsigned int	nb2 = 125;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "% u %-    u";
	const unsigned int	nb1 = 3;
	const unsigned int	nb2 = 125;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test3_bonus(int fd1, int fd2)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "%.0u %-    u";
	const unsigned int	nb1 = 0;
	const unsigned int	nb2 = 125;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test4_bonus(int fd1, int fd2)
{
	const char	*test_name = "test4_bonus: ";
	const char	*str = "%15.0u %-    u";
	const unsigned int	nb1 = 0;
	const unsigned int	nb2 = 125;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test5_bonus(int fd1, int fd2)
{
	const char	*test_name = "test5_bonus: ";
	const char	*str = "%0.8u";
	const unsigned int	nb1 = 1;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

void	u_integer_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, U_INTEGER_TESTS);
	dprintf(fd2, U_INTEGER_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test4(fd1, fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1, fd2);
	test3_bonus(fd1, fd2);
	test4_bonus(fd1, fd2);
	test5_bonus(fd1, fd2);
}

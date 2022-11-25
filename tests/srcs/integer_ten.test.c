/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_ten.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:13:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 15:46:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%i";
	const int	nb = 247558;

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
	const char	*str = "%i";
	const int	nb = INT_MAX;

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
	const char	*str = "%i";
	const int	nb = INT_MIN;

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
	const char	*str = "%i";
	const int	nb = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

static void	test5(int fd1, int fd2)
{
	const char	*test_name = "test5: ";
	const char	*str = "%i";
	const int nb = 114;

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
	const char	*str = "%+ i";
	const int nb = 114;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb);
	dprintf(fd2, "\n");
}

void	integer_ten_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, INTEGER_TEN_TESTS);
	dprintf(fd2, INTEGER_TEN_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test4(fd1, fd2);
	test5(fd1, fd2);
//	test1_bonus();
}

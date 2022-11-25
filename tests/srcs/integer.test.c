/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 19:29:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%d";
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
	const char	*str = "%d";
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
	const char	*str = "%d";
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
	const char	*str = "%d";
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
	const char	*str = "%d % d %d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = -18;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "%+  d % +d %d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = 18;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3);
	dprintf(fd2, "\n");
}

static void	test3_bonus(int fd1, int fd2)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "%+  d % +d % +d %++ +++d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = 18;
	const int	nb4 = 312;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3, nb4);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3, nb4);
	dprintf(fd2, "\n");
}

static void	test4_bonus(int fd1, int fd2)
{
	const char	*test_name = "test4_bonus: ";
	const char	*str = "% d % -d %- d %++ +++d";
	const int	nb1 = 0;
	const int	nb2 = 1234018;
	const int	nb3 = 18;
	const int	nb4 = 312;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3, nb4);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3, nb4);
	dprintf(fd2, "\n");
}

static void	test5_bonus(int fd1, int fd2)
{
	const char	*test_name = "test5_bonus: ";
	const char	*str = "% -d %-d";
	const int	nb1 = 10;
	const int	nb2 = -1234018;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test6_bonus(int fd1, int fd2)
{
	const char	*test_name = "test6_bonus: ";
	const char	*str = "% -d %d";
	const int	nb1 = 10;
	const int	nb2 = 34018;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test7_bonus(int fd1, int fd2)
{
	const char	*test_name = "test7_bonus: ";
	const char	*str = "% -d %10d";
	const int	nb1 = 10;
	const int	nb2 = 34018;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test8_bonus(int fd1, int fd2)
{
	const char	*test_name = "test8_bonus: ";
	const char	*str = "% -d %     9d%10d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3);
	dprintf(fd2, "\n");
}

static void	test9_bonus(int fd1, int fd2)
{
	const char	*test_name = "test9_bonus: ";
	const char	*str = "RESULTAT -> %d,,,,, %d%d%d,,,   ----%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3, nb4, nb5);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3, nb4, nb5);
	dprintf(fd2, "\n");
}

static void	test10_bonus(int fd1, int fd2)
{
	const char	*test_name = "test10_bonus: ";
	const char	*str = "RESULTAT -> %d%34d%d%1000d%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3, nb4, nb5);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3, nb4, nb5);
	dprintf(fd2, "\n");
}

static void	test11_bonus(int fd1, int fd2)
{
	const char	*test_name = "test11_bonus: ";
	const char	*str = "RESULTAT -> %-0 +23d%34d%d%-1000d%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2, nb3, nb4, nb5);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2, nb3, nb4, nb5);
	dprintf(fd2, "\n");
}

static void	test12_bonus(int fd1, int fd2)
{
	const char	*test_name = "test12_bonus: ";
	const char	*str = "RESULTAT -> %-50.42d";
	const int	nb1 = 12349510;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test13_bonus(int fd1, int fd2)
{
	const char	*test_name = "test13_bonus: ";
	const char	*str = "RESULTAT -> %.10d";
	const int	nb1 = 42;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test14_bonus(int fd1, int fd2)
{
	const char	*test_name = "test14_bonus: ";
	const char	*str = "RESULTAT -> %.d";
	const int	nb1 = 42;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test15_bonus(int fd1, int fd2)
{
	const char	*test_name = "test15_bonus: ";
	const char	*str = "RESULTAT -> %.2147483648d";
	const int	nb1 = 42;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test16_bonus(int fd1, int fd2)
{
	const char	*test_name = "test16_bonus: ";
	const char	*str = "%.rd";
	const int	nb1 = -5;
	const int	nb2 = 12;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1, nb2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1, nb2);
	dprintf(fd2, "\n");
}

static void	test17_bonus(int fd1, int fd2)
{
	const char	*test_name = "test17_bonus: ";
	const char	*str = "%.d";
	const int	nb1 = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test18_bonus(int fd1, int fd2)
{
	const char	*test_name = "test18_bonus: ";
	const char	*str = "%0.3d";
	const int	nb1 = -3;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test19_bonus(int fd1, int fd2)
{
	const char	*test_name = "test19_bonus: ";
	const char	*str = "%7.1d";
	const int	nb1 = -3;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test20_bonus(int fd1, int fd2)
{
	const char	*test_name = "test20_bonus: ";
	const char	*str = "%04.9d";
	const int	nb1 = -47;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test21_bonus(int fd1, int fd2)
{
	const char	*test_name = "test21_bonus: ";
	const char	*str = "%-04.9d";
	const int	nb1 = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test22_bonus(int fd1, int fd2)
{
	const char	*test_name = "test22_bonus: ";
	const char	*str = "%-4.d";
	const int	nb1 = -42;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test23_bonus(int fd1, int fd2)
{
	const char	*test_name = "test23_bonus: ";
	const char	*str = "%-10.d";
	const int	nb1 = 0;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test24_bonus(int fd1, int fd2)
{
	const char	*test_name = "test24_bonus: ";
	const char	*str = "%010d";
	const int	nb1 = -4200;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test25_bonus(int fd1, int fd2)
{
	const char	*test_name = "test25_bonus: ";
	const char	*str = "%0.d";
	const int	nb1 = -4200;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test26_bonus(int fd1, int fd2)
{
	const char	*test_name = "test26_bonus: ";
	const char	*str = "%0.0d";
	const int	nb1 = -4200;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

static void	test27_bonus(int fd1, int fd2)
{
	const char	*test_name = "test27_bonus: ";
	const char	*str = "%0.01d";
	const int	nb1 = -4560;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, nb1);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, nb1);
	dprintf(fd2, "\n");
}

void	integer_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, INTEGER_TESTS);
	dprintf(fd2, INTEGER_TESTS);
	test1(fd1,fd2);
	test2(fd1,fd2);
	test3(fd1,fd2);
	test4(fd1,fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1, fd2);
	test3_bonus(fd1, fd2);
	test4_bonus(fd1, fd2);
	test5_bonus(fd1, fd2);
	test6_bonus(fd1, fd2);
	test7_bonus(fd1, fd2);
	test8_bonus(fd1, fd2);
	test9_bonus(fd1, fd2);
	test10_bonus(fd1, fd2);
	test11_bonus(fd1, fd2);
	test12_bonus(fd1, fd2);
	test13_bonus(fd1, fd2);
	test14_bonus(fd1, fd2);
	test15_bonus(fd1, fd2);
	test16_bonus(fd1, fd2);
	test17_bonus(fd1, fd2);
	test18_bonus(fd1, fd2);
	test19_bonus(fd1, fd2);
	test20_bonus(fd1, fd2);
	test21_bonus(fd1, fd2);
	test22_bonus(fd1, fd2);
	test23_bonus(fd1, fd2);
	test24_bonus(fd1, fd2);
	test25_bonus(fd1, fd2);
	test26_bonus(fd1, fd2);
	test27_bonus(fd1, fd2);
/*
*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/24 14:59:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%d";
	const int	nb = 247558;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb);
	printf("\n");
}

static void	test2(void)
{
	const char	*test_name = "test2: ";
	const char	*str = "%d";
	const int	nb = INT_MAX;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb);
	printf("\n");
}

static void	test3(void)
{
	const char	*test_name = "test3: ";
	const char	*str = "%d";
	const int	nb = INT_MIN;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb);
	printf("\n");
}

static void	test4(void)
{
	const char	*test_name = "test4: ";
	const char	*str = "%d";
	const unsigned int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb);
	printf("\n");
}

static void	test1_bonus(void)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "%d % d %d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = -18;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3);
	printf("\n");
}

static void	test2_bonus(void)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "%+  d % +d %d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = 18;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3);
	printf("\n");
}

static void	test3_bonus(void)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "%+  d % +d % +d %++ +++d";
	const int	nb1 = 0;
	const int	nb2 = -1234018;
	const int	nb3 = 18;
	const int	nb4 = 312;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3, nb4);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3, nb4);
	printf("\n");
}

static void	test4_bonus(void)
{
	const char	*test_name = "test4_bonus: ";
	const char	*str = "% d % -d %- d %++ +++d";
	const int	nb1 = 0;
	const int	nb2 = 1234018;
	const int	nb3 = 18;
	const int	nb4 = 312;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3, nb4);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3, nb4);
	printf("\n");
}

static void	test5_bonus(void)
{
	const char	*test_name = "test5_bonus: ";
	const char	*str = "% -d %-d";
	const int	nb1 = 10;
	const int	nb2 = -1234018;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test6_bonus(void)
{
	const char	*test_name = "test6_bonus: ";
	const char	*str = "% -d %d";
	const int	nb1 = 10;
	const int	nb2 = 34018;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test7_bonus(void)
{
	const char	*test_name = "test7_bonus: ";
	const char	*str = "% -d %10d";
	const int	nb1 = 10;
	const int	nb2 = 34018;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test8_bonus(void)
{
	const char	*test_name = "test8_bonus: ";
	const char	*str = "% -d %     9d%10d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3);
	printf("\n");
}

static void	test9_bonus(void)
{
	const char	*test_name = "test9_bonus: ";
	const char	*str = "RESULTAT -> %d,,,,, %d%d%d,,,   ----%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3, nb4, nb5);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3, nb4, nb5);
	printf("\n");
}

static void	test10_bonus(void)
{
	const char	*test_name = "test10_bonus: ";
	const char	*str = "RESULTAT -> %d%34d%d%1000d%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3, nb4, nb5);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3, nb4, nb5);
	printf("\n");
}

static void	test11_bonus(void)
{
	const char	*test_name = "test11_bonus: ";
	const char	*str = "RESULTAT -> %-0 +23d%34d%d%-1000d%d";
	const int	nb1 = -12349510;
	const int	nb2 = INT_MAX;
	const int	nb3 = 34018;
	const int	nb4 = 45;
	const int	nb5 = 2;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2, nb3, nb4, nb5);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2, nb3, nb4, nb5);
	printf("\n");
}

static void	test12_bonus(void)
{
	const char	*test_name = "test12_bonus: ";
	const char	*str = "RESULTAT -> %-50.42d";
	const int	nb1 = 12349510;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test13_bonus(void)
{
	const char	*test_name = "test13_bonus: ";
	const char	*str = "RESULTAT -> %.10d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test14_bonus(void)
{
	const char	*test_name = "test14_bonus: ";
	const char	*str = "RESULTAT -> %.d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test15_bonus(void)
{
	const char	*test_name = "test15_bonus: ";
	const char	*str = "RESULTAT -> %.2147483648d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test16_bonus(void)
{
	const char	*test_name = "test16_bonus: ";
	const char	*str = "%.rd";
	const int	nb1 = -5;
	const int	nb2 = 12;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test17_bonus(void)
{
	const char	*test_name = "test17_bonus: ";
	const char	*str = "%.d";
	const int	nb1 = 0;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test18_bonus(void)
{
	const char	*test_name = "test18_bonus: ";
	const char	*str = "%0.3d";
	const int	nb1 = -3;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test19_bonus(void)
{
	const char	*test_name = "test19_bonus: ";
	const char	*str = "%7.1d";
	const int	nb1 = -3;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test20_bonus(void)
{
	const char	*test_name = "test20_bonus: ";
	const char	*str = "%04.9d";
	const int	nb1 = -47;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test21_bonus(void)
{
	const char	*test_name = "test21_bonus: ";
	const char	*str = "%-04.9d";
	const int	nb1 = 0;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test22_bonus(void)
{
	const char	*test_name = "test22_bonus: ";
	const char	*str = "%-4.d";
	const int	nb1 = -42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test23_bonus(void)
{
	const char	*test_name = "test23_bonus: ";
	const char	*str = "%-10.d";
	const int	nb1 = 0;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test24_bonus(void)
{
	const char	*test_name = "test24_bonus: ";
	const char	*str = "%010d";
	const int	nb1 = -4200;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

void	integer_tests(void)
{
	ft_printf(INTEGER_TESTS);
	printf(INTEGER_TESTS);
	test1();
	test2();
	test3();
	test4();
	test1_bonus();
	test2_bonus();
	test3_bonus();
	test4_bonus();
	test5_bonus();
	test6_bonus();
	test7_bonus();
	test8_bonus();
	test9_bonus();
	test10_bonus();
	test11_bonus();
	test12_bonus();
	test13_bonus();
	test14_bonus();
	test15_bonus();
	test16_bonus();
	test17_bonus();
	test18_bonus();
	test19_bonus();
	test20_bonus();
	test21_bonus();
	test22_bonus();
	test23_bonus();
//	test24_bonus();
/*
*/
}

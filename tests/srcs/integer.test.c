/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 11:19:00 by rbroque          ###   ########.fr       */
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

static void	test5(void)
{
	const char	*test_name = "test5: ";
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

static void	test6(void)
{
	const char	*test_name = "test6: ";
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

static void	test7(void)
{
	const char	*test_name = "test7: ";
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

static void	test8(void)
{
	const char	*test_name = "test8: ";
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

static void	test9(void)
{
	const char	*test_name = "test9: ";
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

static void	test10(void)
{
	const char	*test_name = "test10: ";
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

static void	test11(void)
{
	const char	*test_name = "test11: ";
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

static void	test12(void)
{
	const char	*test_name = "test12: ";
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

static void	test13(void)
{
	const char	*test_name = "test13: ";
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

static void	test14(void)
{
	const char	*test_name = "test14: ";
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

static void	test15(void)
{
	const char	*test_name = "test15: ";
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

static void	test16(void)
{
	const char	*test_name = "test16: ";
	const char	*str = "RESULTAT -> %-50.42d";
	const int	nb1 = 12349510;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test17(void)
{
	const char	*test_name = "test17: ";
	const char	*str = "RESULTAT -> %.10d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test18(void)
{
	const char	*test_name = "test18: ";
	const char	*str = "RESULTAT -> %.d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test19(void)
{
	const char	*test_name = "test19: ";
	const char	*str = "RESULTAT -> %.2147483648d";
	const int	nb1 = 42;

	ft_printf(test_name);
	ft_printf(str, nb1);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1);
	printf("\n");
}

static void	test20(void)
{
	const char	*test_name = "test20: ";
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

static void	test21(void)
{
	const char	*test_name = "test21: ";
	const char	*str = "%.d";
	const int	nb1 = 0;

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
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test19();
	test20();
	test21();
}

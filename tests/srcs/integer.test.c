/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:03:15 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/19 17:02:55 by rbroque          ###   ########.fr       */
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
	const char	*str = "%  d % d %d";
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
	const char	*str = "%1d % +d % +d %++ +++d";
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
}

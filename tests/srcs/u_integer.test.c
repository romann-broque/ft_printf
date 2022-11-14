/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:08:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 11:46:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%u";
	const unsigned int	nb = 247558;

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
	const char	*str = "%u";
	const unsigned int	nb = INT_MAX;

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
	const char	*str = "%u";
	const unsigned int	nb = UINT_MAX;

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
	const char	*str = "%u";
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
	const char	*str = "% u %    u";
	const unsigned int	nb1 = 3;
	const unsigned int	nb2 = 125;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test6(void)
{
	const char	*test_name = "test6: ";
	const char	*str = "% u %-    u";
	const unsigned int	nb1 = 3;
	const unsigned int	nb2 = 125;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

static void	test7(void)
{
	const char	*test_name = "test7: ";
	const char	*str = "%.0u %-    u";
	const unsigned int	nb1 = 0;
	const unsigned int	nb2 = 125;

	ft_printf(test_name);
	ft_printf(str, nb1, nb2);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb1, nb2);
	printf("\n");
}

void	u_integer_tests(void)
{
	ft_printf(U_INTEGER_TESTS);
	printf(U_INTEGER_TESTS);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_ten.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:13:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 16:34:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%i";
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
	const char	*str = "%i";
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
	const char	*str = "%i";
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
	const char	*str = "%i";
	const int	nb = 0;

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
	const char	*str = "%i";
	const int nb = 114;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	printf(test_name);
	printf(str, nb);
	printf("\n");
}

void	integer_ten_tests(void)
{
	ft_printf(INTEGER_TEN_TESTS);
	printf(INTEGER_TEN_TESTS);
	test1();
	test2();
	test3();
	test4();
	test5();
}

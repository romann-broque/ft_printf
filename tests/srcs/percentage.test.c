/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:23:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 19:07:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%%";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test2(void)
{
	const char	*test_name = "test2: ";
	const char	*str = "%% %%%%";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test3(void)
{
	const char	*test_name = "test3: ";
	const char	*str = "%% %%%%%";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test4(void)
{
	const char	*test_name = "test4: ";
	const char	*str = "%% %%%%% %";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test5(void)
{
	const char	*test_name = "test5: ";
	const char	*str = "qw%% %%%%% %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test6(void)
{
	const char	*test_name = "test6: ";
	const char	*str = "qw%%  \n%%%%%     %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}


void	percentage_tests(void)
{
	ft_printf(PERCENTAGE_TESTS);
	printf(PERCENTAGE_TESTS);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}

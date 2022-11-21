/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:23:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 15:24:37 by rbroque          ###   ########.fr       */
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

static void	test1_bonus(void)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "qw%% %%%%% %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test2_bonus(void)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "qw%%  \n%%%%%     %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	printf(test_name);
	printf(str);
	printf("\n");
}

static void	test3_bonus(void)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "qw%%  \n%10%  39%%%     %; v%% % %jjjj%%% %%rqwqqvsf";

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
/*
	test1_bonus();
	test2_bonus();
	test3_bonus();
*/
}

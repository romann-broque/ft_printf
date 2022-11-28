/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:23:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 17:46:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%%";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test2(int fd1, int fd2)
{
	const char	*test_name = "test2: ";
	const char	*str = "%% %%%%";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test3(int fd1, int fd2)
{
	const char	*test_name = "test3: ";
	const char	*str = "%% %%%%%";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test4(int fd1, int fd2)
{
	const char	*test_name = "test4: ";
	const char	*str = "%% %%%%% %";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test1_bonus(int fd1, int fd2)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "qw%% %%%%% %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "qw%%  \n%%%%%     %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}

static void	test3_bonus(int fd1, int fd2)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "qw%%  \n%10%  39%%%     %; v%% % %jjjj%%% %%rqwqqvsf";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str);
	dprintf(fd2, "\n");
}


void	percentage_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, PERCENTAGE_TESTS);
	dprintf(fd2, PERCENTAGE_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test4(fd1, fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1, fd2);
	test3_bonus(fd1, fd2);
/*
*/
}

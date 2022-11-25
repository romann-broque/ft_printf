/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:28:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 15:36:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "wouah";

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
	const char	*str1 = "wou%sah";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test3(int fd1, int fd2)
{
	const char	*test_name = "test3: ";
	const char	*str1 = "wou%s";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test4(int fd1, int fd2)
{
	const char	*test_name = "test4: ";
	const char	*str1 = "wou%";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test5(int fd1, int fd2)
{
	const char	*test_name = "test5: ";
	const char	*str1 = "wou% ";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test6(int fd1, int fd2)
{
	const char	*test_name = "test6: ";
	const char	*str1 = "wou%s% ";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test7(int fd1, int fd2)
{
	const char	*test_name = "test7: ";
	const char	*str1 = "wou%z%";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test8(int fd1, int fd2)
{
	const char	*test_name = "test8: ";
	const char	*str1 = "wou%w%s";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test9(int fd1, int fd2)
{
	const char	*test_name = "test9: ";
	const char	*str1 = "%";
	const char	*str2 = "incredible";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test10(int fd1, int fd2)
{
	const char	*test_name = "test10: ";
	const char	*str1 = "%s";
	const char	*str2 = NULL;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test11(int fd1, int fd2)
{
	const char	*test_name = "test11: ";
	const char	*str1 = "%s\n";
	const char	*str2 = NULL;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test1_bonus(int fd1, int fd2)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str1 = "%s    \n";
	const char	*str2 = "";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str1 = "%s    %s	% sa sdasdasdSSSSSS";
	const char	*str2 = "";
	const char	*str3 = "asdasd";
	const char	*str4 = "ougiouhug";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2, str3, str4);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2, str3, str4);
	dprintf(fd2, "\n");
}

static void	test3_bonus(int fd1, int fd2)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str1 = "%.2s";
	const char	*str2 = "Hello";

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

static void	test4_bonus(int fd1, int fd2)
{
	const char	*test_name = "test4_bonus: ";
	const char	*str1 = "%.5s";
	const char	*str2 = NULL;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str1, str2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str1, str2);
	dprintf(fd2, "\n");
}

void	string_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, STRING_TESTS);
	dprintf(fd2, STRING_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test4(fd1, fd2);
	test5(fd1, fd2);
	test6(fd1, fd2);
	test7(fd1, fd2);
	test8(fd1, fd2);
	test9(fd1, fd2);
	test10(fd1, fd2);
//	test11();
//	test1_bonus();
	test2_bonus(fd1, fd2);
	test3_bonus(fd1, fd2);
	test4_bonus(fd1, fd2);
/*
*/
}

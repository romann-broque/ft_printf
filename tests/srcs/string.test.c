/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:28:33 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 18:20:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "wouah";

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
	const char	*str1 = "wou%sah";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test3(void)
{
	const char	*test_name = "test3: ";
	const char	*str1 = "wou%s";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test4(void)
{
	const char	*test_name = "test4: ";
	const char	*str1 = "wou%";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test5(void)
{
	const char	*test_name = "test5: ";
	const char	*str1 = "wou% ";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test6(void)
{
	const char	*test_name = "test6: ";
	const char	*str1 = "wou%s% ";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test7(void)
{
	const char	*test_name = "test7: ";
	const char	*str1 = "wou%z%";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test8(void)
{
	const char	*test_name = "test8: ";
	const char	*str1 = "wou%w%s";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test9(void)
{
	const char	*test_name = "test9: ";
	const char	*str1 = "%";
	const char	*str2 = "incredible";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test10(void)
{
	const char	*test_name = "test10: ";
	const char	*str1 = "%s";
	const char	*str2 = NULL;

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test11(void)
{
	const char	*test_name = "test11: ";
	const char	*str1 = "%s\n";
	const char	*str2 = NULL;

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test12(void)
{
	const char	*test_name = "test12: ";
	const char	*str1 = "%s    \n";
	const char	*str2 = "";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test13(void)
{
	const char	*test_name = "test13: ";
	const char	*str1 = "%s    \n%s	% sa sdasdasdSSSSSS";
	const char	*str2 = "";
	const char	*str3 = "asdasd";
	const char	*str4 = "ougiouhug";

	ft_printf(test_name);
	ft_printf(str1, str2, str3, str4);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2, str3, str4);
	printf("\n");
}

static void	test14(void)
{
	const char	*test_name = "test14: ";
	const char	*str1 = "%.2s";
	const char	*str2 = "Hello";

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

static void	test15(void)
{
	const char	*test_name = "test15: ";
	const char	*str1 = "%.5s";
	const char	*str2 = NULL;

	ft_printf(test_name);
	ft_printf(str1, str2);
	ft_printf("\n");

	printf(test_name);
	printf(str1, str2);
	printf("\n");
}

void	string_tests(void)
{
	ft_printf(STRING_TESTS);
	printf(STRING_TESTS);
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
	//test15();
}

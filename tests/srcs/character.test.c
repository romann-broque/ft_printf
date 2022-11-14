/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 20:26:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%c";
	const char	character = 'a';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test2(void)
{
	const char	*test_name = "test2: ";
	const char	*str = "%c";
	const unsigned char	character = UCHAR_MAX;

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test3(void)
{
	const char	*test_name = "test3: ";
	const char	*str = "%c %c %c %c %c";
	const unsigned char	character1 = UCHAR_MAX;
	const char	character2 = 'c';
	const char	character3 = '1';
	const char	character4 = '9';
	const char	character5 = '1';

	ft_printf(test_name);
	ft_printf(str, character1, character2, character3, character4, character5);
	ft_printf("\n");

	printf(test_name);
	printf(str, character1, character2, character3, character4, character5);
	printf("\n");
}

static void	test4(void)
{
	const char	*test_name = "test4: ";
	const char	*str = "Charlott%c";
	const char	character = 'e';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test5(void)
{
	const char	*test_name = "test5: ";
	const char	*str = "%   -0c";
	const char	character = 'e';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test6(void)
{
	const char	*test_name = "test6: ";
	const char	*str = "% c";
	const char	character = '\0';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test7(void)
{
	const char	*test_name = "test7: ";
	const char	*str = "c% casd";
	const char	character = '\0';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	printf(test_name);
	printf(str, character);
	printf("\n");
}

static void	test8(void)
{
	const char	*test_name = "test8: ";
	const char	*str = "c% cas%       cccd";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_printf(test_name);
	ft_printf(str, character, character2);
	ft_printf("\n");

	printf(test_name);
	printf(str, character, character2);
	printf("\n");
}

static void	test9(void)
{
	const char	*test_name = "test9: ";
	const char	*str = "c%c%c%";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_printf(test_name);
	ft_printf(str, character, character2);
	ft_printf("\n");

	printf(test_name);
	printf(str, character, character2);
	printf("\n");
}

void	character_tests(void)
{
	ft_printf(CHAR_TESTS);
	printf(CHAR_TESTS);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}

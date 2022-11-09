/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/09 09:43:43 by rbroque          ###   ########.fr       */
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

void	character_tests(void)
{
	ft_printf(CHAR_TESTS);
	printf(CHAR_TESTS);
	test1();
	test2();
	test3();
	test4();
}

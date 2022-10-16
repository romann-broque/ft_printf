/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 18:41:17 by rbroque          ###   ########.fr       */
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
	const char	character = UCHAR_MAX;

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
}

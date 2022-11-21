/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:29:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/21 17:06:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(void)
{
	const char	*test_name = "test1: ";
	const char	*str = "%p";
	char		*ptr;

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");

	printf(test_name);
	printf(str, ptr);
	printf("\n");
}

static void	test2(void)
{
	const char	*test_name = "test2: ";
	const char	*str = "%p";
	char		*ptr = NULL;

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");

	printf(test_name);
	printf(str, ptr);
	printf("\n");
}

static void	test1_bonus(void)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "%+#  p";
	char		*ptr;

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");

	printf(test_name);
	printf(str, ptr);
	printf("\n");
}

static void	test2_bonus(void)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "% p";
	char		*ptr;

	ptr = (char *)ULONG_MAX;
	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");

	printf(test_name);
	printf(str, ptr);
	printf("\n");
}

void	address_tests(void)
{
	ft_printf(ADDRESS_TESTS);
	printf(ADDRESS_TESTS);
	test1();
	test2();
//	test1_bonus();
//	test2_bonus();
}

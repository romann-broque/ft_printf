/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 14:02:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SEPARATOR "-----------\n"

void	test1(void)
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

void	test2(void)
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

void	test3(void)
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

void	test4(void)
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

void	test5(void)
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

void	test6(void)
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

void	test7(void)
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

int	main(void)
{
	printf(SEPARATOR);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return (EXIT_SUCCESS);
}

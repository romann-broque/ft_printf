/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:29:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 16:01:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%p";
	char		*ptr;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, ptr);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, ptr);
	dprintf(fd2, "\n");
}

static void	test2(int fd1, int fd2)
{
	const char	*test_name = "test2: ";
	const char	*str = "%p";
	char		*ptr = NULL;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, ptr);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, ptr);
	dprintf(fd2, "\n");
}

static void	test1_bonus(int fd1, int fd2)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "%+#  p";
	char		*ptr;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, ptr);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, ptr);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "% p";
	char		*ptr;

	ptr = (char *)ULONG_MAX;
	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, ptr);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, ptr);
	dprintf(fd2, "\n");
}

void	address_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, ADDRESS_TESTS);
	dprintf(fd2, ADDRESS_TESTS);
	test1(fd1, fd2);
	test2(fd1, fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1 ,fd2);
/*
*/
}

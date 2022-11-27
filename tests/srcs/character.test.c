/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:51 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/27 20:47:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

static void	test1(int fd1, int fd2)
{
	const char	*test_name = "test1: ";
	const char	*str = "%c";
	const char	character = 'a';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test2(int fd1, int fd2)
{
	const char	*test_name = "test2: ";
	const char	*str = "%c";
	const unsigned char	character = UCHAR_MAX;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test3(int fd1, int fd2)
{
	const char	*test_name = "test3: ";
	const char	*str = "%c %c %c %c %c";
	const unsigned char	character1 = UCHAR_MAX;
	const char	character2 = 'c';
	const char	character3 = '1';
	const char	character4 = '9';
	const char	character5 = '1';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character1, character2, character3, character4, character5);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character1, character2, character3, character4, character5);
	dprintf(fd2, "\n");
}

static void	test4(int fd1, int fd2)
{
	const char	*test_name = "test4: ";
	const char	*str = "Charlott%c";
	const char	character = 'e';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test5(int fd1, int fd2)
{
	const char	*test_name = "test5: ";
	const char	*str = "%cp";
	const char	character = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test6(int fd1, int fd2)
{
	const char	*test_name = "test6: ";
	const char	*str = "%c%c%c%";
	const char	character = '\0';
	const char	character2 = '\0';
	const char	character3 = 1;

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character, character2, character3);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character, character2, character3);
	dprintf(fd2, "\n");
}

static void	test7(int fd1, int fd2)
{
	const char	*test_name = "test7: ";
	const char	*str = "c%c%c%";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character, character2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character, character2);
	dprintf(fd2, "\n");
}

static void	test8(int fd1, int fd2)
{
	const char	*test_name = "test8: ";
	const char	*str = "wouah%c%chello";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character, character2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character, character2);
	dprintf(fd2, "\n");
}

// BONUS
static void	test1_bonus(int fd1, int fd2)
{
	const char	*test_name = "test1_bonus: ";
	const char	*str = "%   -0c";
	const char	character = 'e';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test2_bonus(int fd1, int fd2)
{
	const char	*test_name = "test2_bonus: ";
	const char	*str = "% c";
	const char	character = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test3_bonus(int fd1, int fd2)
{
	const char	*test_name = "test3_bonus: ";
	const char	*str = "c% casd";
	const char	character = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test4_bonus(int fd1, int fd2)
{
	const char	*test_name = "test4_bonus: ";
	const char	*str = "c% cas%       cccd";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character, character2);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character, character2);
	dprintf(fd2, "\n");
}

static void	test5_bonus(int fd1, int fd2)
{
	const char	*test_name = "test5_bonus: ";
	const char	*str = "c%0c";
	const char	character = 'a';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

static void	test6_bonus(int fd1, int fd2)
{
	const char	*test_name = "test6_bonus: ";
	const char	*str = "%2c";
	const char	character = '\0';

	ft_dprintf(fd1, test_name);
	ft_dprintf(fd1, str, character);
	ft_dprintf(fd1, "\n");

	dprintf(fd2, test_name);
	dprintf(fd2, str, character);
	dprintf(fd2, "\n");
}

void	character_tests(int fd1, int fd2)
{
	ft_dprintf(fd1, CHAR_TESTS);
	dprintf(fd2, CHAR_TESTS);
/*
	test1(fd1, fd2);
	test2(fd1, fd2);
	test3(fd1, fd2);
	test4(fd1, fd2);
	test5(fd1, fd2);
	test6(fd1, fd2);
	test7(fd1, fd2);
	test8(fd1, fd2);
	test1_bonus(fd1, fd2);
	test2_bonus(fd1, fd2);
	test3_bonus(fd1, fd2);
	test4_bonus(fd1, fd2);
	test5_bonus(fd1, fd2);
*/
	test6_bonus(fd1, fd2);
}

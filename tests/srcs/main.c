/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 17:46:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("tests/assets/cache1", O_WRONLY);
	fd2 = open("tests/assets/cache2", O_WRONLY);
	character_tests(fd1, fd2);
	string_tests(fd1, fd2);
	percentage_tests(fd1, fd2);
	integer_tests(fd1, fd2);
	integer_ten_tests(fd1, fd2);
	u_integer_tests(fd1, fd2);
	low_hex_tests(fd1, fd2);
	up_hex_tests(fd1, fd2);
	address_tests(fd1, fd2);
/*
*/
	close(fd1);
	close(fd2);
	return (EXIT_SUCCESS);
}

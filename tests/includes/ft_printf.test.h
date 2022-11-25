/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:31:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/25 14:39:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# include "ft_printf.h"
# define SEPARATOR "<------------------------------------------------------->\n"
# define STRING_TESTS "\n-----STRING TESTS-----\n"
# define CHAR_TESTS "\n-----CHAR TESTS-----\n"
# define LOW_HEX_TESTS "\n-----LOW HEX TESTS-----\n"
# define UP_HEX_TESTS "\n-----UP HEX TESTS-----\n"
# define ADDRESS_TESTS "\n-----ADDRESS TESTS-----\n"
# define INTEGER_TESTS "\n-----INTEGER TESTS-----\n"
# define U_INTEGER_TESTS "\n-----U_INTEGER TESTS-----\n"
# define INTEGER_TEN_TESTS "\n-----INTEGER TEN TESTS-----\n"
# define PERCENTAGE_TESTS "\n-----PERCENTAGE TESTS-----\n"

void	string_tests(int fd1, int fd2);
void	character_tests(int fd1, int fd2);
void	low_hex_tests(int fd1, int fd2);
void	up_hex_tests(int fd1, int fd2);
void	address_tests(int fd1, int fd2);
void	integer_tests(int fd1, int fd2);
void	u_integer_tests(int fd1, int fd2);
void	integer_ten_tests(int fd1, int fd2);
void	percentage_tests(int fd1, int fd2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:31:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 18:51:07 by rbroque          ###   ########.fr       */
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
# define SEPARATOR "<---------------------------->\n"
# define STRING_TESTS "-----STRING TESTS-----\n"
# define CHAR_TESTS "-----CHAR TESTS-----\n"

void	string_tests(void);
void	character_tests(void);

#endif

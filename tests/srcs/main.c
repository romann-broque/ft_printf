/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 19:49:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

int	main(void)
{
	printf(SEPARATOR);
	character_tests();
/*
	string_tests();
	percentage_tests();
	low_hex_tests();
	up_hex_tests();
	address_tests();
	integer_tests();
	u_integer_tests();
	integer_ten_tests();
*/
	return (EXIT_SUCCESS);
}

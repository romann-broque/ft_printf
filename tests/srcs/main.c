/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 15:10:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

int	main(void)
{
	printf(SEPARATOR);
	string_tests();
	character_tests();
	low_hex_tests();
	up_hex_tests();
	address_tests();
	integer_tests();
	u_integer_tests();
	percentage_tests();
	return (EXIT_SUCCESS);
}

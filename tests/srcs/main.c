/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 18:39:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.test.h"

int	main(void)
{
	printf(SEPARATOR);
	string_tests();
	character_tests();
	return (EXIT_SUCCESS);
}

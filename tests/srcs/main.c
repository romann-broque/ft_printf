/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 13:11:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SEPARATOR "\n-----------\n"

void	test1(void)
{
	const char	*str = "wouah";

	ft_printf(str);
	printf(str);
}

void	test2(void)
{
	const char	*str1 = "wou%sah";
	const char	*str2 = "incredible";

	ft_printf(str1, str2);
	printf(str1, str2);
}

int	main(void)
{
	printf(SEPARATOR);
	test1();
	test2();
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:42 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/14 17:22:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_printf(av[1]);
		printf("\n");
		printf(av[1]);
	}
	else if (ac == 3)
	{
		ft_printf(av[1], av[2]);
		printf("\n");
		printf(av[1], av[2]);
	}
	else if (ac == 4)
	{
		ft_printf(av[1], av[2], av[3]);
		printf("\n");
		printf(av[1], av[2], av[3]);
	}
	else if (ac == 5)
	{
		ft_printf(av[1], av[2], av[3], av[4]);
		printf("\n");
		printf(av[1], av[2], av[3], av[4]);
	}
	else if (ac == 6)
	{
		ft_printf(av[1], av[2], av[3], av[4], av[5]);
		printf("\n");
		printf(av[1], av[2], av[3], av[4], av[5]);
	}
	else if (ac == 7)
	{
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6]);
		printf("\n");
		printf(av[1], av[2], av[3], av[4], av[5], av[6]);
	}
	else
		return (EXIT_FAILURE);
	printf("\n");
	return (EXIT_SUCCESS);
}

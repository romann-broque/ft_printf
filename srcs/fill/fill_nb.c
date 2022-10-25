/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:19 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 17:40:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_pos_nb(unsigned int n, t_machine *machine)
{
	const char	digit = n % 10 + '0';

	if (n > 0)
	{
		fill_pos_nb(n / 10, machine);
		cpy_data(machine, (char *)&digit, sizeof(char));
	}
}

void	fill_nbr(int n, t_machine *machine)
{
	const char		minus = '-';
	unsigned int	abs_n;

	abs_n = n;
	if (n < 0)
	{
		cpy_data(machine, (char *)&minus, sizeof(char));
		abs_n = -n;
	}
	fill_unbr(abs_n, machine);
}

void	fill_unbr(unsigned int n, t_machine *machine)
{
	const char		zero = '0';

	if (n == 0)
		cpy_data(machine, (char *)&zero, sizeof(char));
	fill_pos_nb(n, machine);
}

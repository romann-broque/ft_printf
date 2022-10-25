/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:43 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 17:25:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_hex_pos(const char *hbase, const unsigned int nb, t_machine *machine)
{
	if (nb != 0)
	{
		fill_hex_pos(hbase, nb / 16, machine);
		cpy_data(machine, (char *)(hbase + (nb % 16)), sizeof(char));
	}
}

static void	fill_lhex_pos(const char *hbase, const unsigned long nb, t_machine *machine)
{
	if (nb != 0)
	{
		fill_lhex_pos(hbase, nb / 16, machine);
		cpy_data(machine, (char *)(hbase + (nb % 16)), sizeof(char));
	}
}

void	fill_hex(const char *hbase, const unsigned int nb, t_machine *machine)
{
	const char	zero = '0';

	if (nb == 0)
		cpy_data(machine, (char *)&zero, sizeof(char));
	fill_hex_pos(hbase, nb, machine);
}

void	fill_lhex(const char *hbase, const unsigned long nb, t_machine *machine)
{
	const char	zero = '0';

	if (nb == 0)
		cpy_data(machine, (char *)&zero, sizeof(char));
	fill_lhex_pos(hbase, nb, machine);
}

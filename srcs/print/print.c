/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:30:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/19 17:35:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(t_machine *machine)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = machine->width;
	if (width > 0)
	{
		--width;
		while (i < width)
		{
			ft_putstr_fd(WIDTH_UNIT, machine->fd);
			++i;
		}
	}
}

void	print(t_machine *machine, ssize_t option_index)
{
	static void		(*print_arg[])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};

	if (machine->flags & MINUS_FLAG)
	{
		print_arg[option_index](machine);
		print_width(machine);
	}
	else
	{
		print_width(machine);
		print_arg[option_index](machine);
	}
}

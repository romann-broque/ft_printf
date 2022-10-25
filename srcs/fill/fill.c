/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:22:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 17:22:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill(t_machine *machine, ssize_t option_index)
{
	static void		(*fill_arg[])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};

/*
	get_widthsize(machine, option_index);
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
*/
	fill_arg[option_index](machine);
}

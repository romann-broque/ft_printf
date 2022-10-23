/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:30:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/23 18:47:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_machine *machine, ssize_t option_index)
{
	static void		(*print_arg[])(t_machine *) = {string, character, low_hex,
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
	print_arg[option_index](machine);
}

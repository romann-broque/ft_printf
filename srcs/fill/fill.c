/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:22:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 18:24:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	fill_width(t_machine *machine)
{
	char	*width;

	width = (char *)malloc(machine->width * sizeof(char));
	if (width != NULL)
	{
		ft_memset(width, WIDTH_UNIT, machine->width);
		cpy_data(machine->width);
		free(width);
	}
}
*/

void	fill(t_machine *machine, ssize_t option_index)
{
	static void		(*fill_arg[])(t_machine *) = {string, character, low_hex,
		up_hex, address, integer, u_integer, integer_ten, percentage};

/*
	get_widthsize(machine, option_index);
	if (machine->flags & MINUS_FLAG)
	{
//		fill_arg[option_index](machine);
		fill_width(machine);
	}
	else
	{
//		fill_width(machine);
		fill_arg[option_index](machine);
	}
*/
	fill_arg[option_index](machine);
}

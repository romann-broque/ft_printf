/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:44 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/25 17:38:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer(t_machine *machine)
{
	const int	nb = va_arg(machine->aptr, int);
	const char	plus = '+';
	const char	space = ' ';

	if (nb >= 0)
	{
		if (machine->flags & PLUS_FLAG)
			cpy_data(machine, (char *)&plus, sizeof(char));
		else if (machine->width == 0 && machine->flags & SPACE_FLAG)
			cpy_data(machine, (char *)&space, sizeof(char));
	}
	fill_nbr(nb, machine);
}

void	u_integer(t_machine *machine)
{
	const unsigned int	nb = va_arg(machine->aptr, unsigned int);

	fill_unbr(nb, machine);
}

void	integer_ten(t_machine *machine)
{
	integer(machine);
}

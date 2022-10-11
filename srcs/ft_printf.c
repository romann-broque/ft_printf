/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/11 12:46:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_state	get_next_state(t_machine *machine)
{
	if (machine->curr_c == OPTION_CHAR)
		machine->state = E_OPTION;
	if (machine->curr_c == '\0')
		machine->state = E_END;
	else
		++(machine->curr_c);
	return (machine->state);
}

int	ft_printf(const char *str, ...)
{
//	static void	*(*state_action[])(va_list) = {string};
//	va_list		aptr;
	t_machine	*machine;

//	va_start(aptr, str);
	machine = init_machine(str);
	while (get_next_state(machine) != E_END)
	{
//		state_action[machine->state](aptr);
	}
	free(machine);
//	va_end(aptr);
	return (EXIT_SUCCESS);
}

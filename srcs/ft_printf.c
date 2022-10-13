/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/13 12:08:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_option(t_machine *machine)
{
	static void	*(*actions[])(va_list) = {input};
	char		option;

	OPTIONS[get_index()](machine);

}

enum e_state	get_next_state(t_machine *machine)
{
	const char	curr_c = (machine->input)[machine->index];

	if (machine->state == E_OPTION)
	{
		++(machine->index);
		get_option(machine);
	}
	else
	{
		if (curr_c == OPTION_CHAR)
		{
			machine->state = E_OPTION;
			printf("%c\n", OPTION_CHAR);
		}
		if (curr_c == '\0')
			machine->state = E_END;
		else
			++(machine->index);
	}
	return (machine->state);
}

int	ft_printf(const char *str, ...)
{
//	static void	*(*state_action[])(va_list) = {input};
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

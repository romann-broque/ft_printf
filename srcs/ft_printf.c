/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/13 17:44:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_option(t_machine *machine)
{
	static void	(*actions[])(void) = {string};
	const char	curr_c = (machine->input)[machine->index];
	const size_t	option_index = get_index(OPTIONS, curr_c);

	if (option_index < NBOF_OPTIONS)
		actions[option_index]();
	else
		printf("ERROR !\n");
	machine->state = E_IDLE;
}

enum e_state	get_next_state(t_machine *machine)
{
	char	curr_c = (machine->input)[machine->index];

	if (machine->state == E_OPTION)
		get_option(machine);
	else if (curr_c == OPTION_CHAR)
		machine->state = E_OPTION;
	else if (curr_c == '\0')
		machine->state = E_END;
	else
		printf("%c", curr_c);
	++(machine->index);
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
		//	if (machine->state == E_IDLE)
		//		state_action[machine->state](aptr);
	}
	free(machine);
	//	va_end(aptr);
	return (EXIT_SUCCESS);
}

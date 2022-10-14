/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:17 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/14 18:23:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_option(t_machine *machine)
{
	static void		(*actions[])(t_machine *) = {string};
	const char		curr_c = (machine->input)[machine->index];
	const size_t	option_index = get_index(OPTIONS, curr_c);

	if (option_index < NBOF_OPTIONS)
		actions[option_index](machine);
	else if (machine->input[machine->index + 1] != '\0')
	{
		ft_putchar_fd(OPTION_CHAR, STDOUT_FILENO);
		ft_putchar_fd(curr_c, STDOUT_FILENO);
	}
	machine->state = E_IDLE;
}

enum e_state	get_next_state(t_machine *machine)
{
	char	curr_c = (machine->input)[machine->index];

	if (curr_c == '\0')
		machine->state = E_END;
	else if (machine->state == E_OPTION)
		get_option(machine);
	else if (curr_c == OPTION_CHAR)
		machine->state = E_OPTION;
	else
		ft_putchar_fd(curr_c, STDOUT_FILENO);
	++(machine->index);
	return (machine->state);
}

int	ft_printf(const char *str, ...)
{
	va_list		aptr;
	t_machine	*machine;

	va_start(aptr, str);
	machine = init_machine(str, aptr);
	while (get_next_state(machine) != E_END)
	{
		//	if (machine->state == E_IDLE)
		//		state_action[machine->state](aptr);
	}
	free(machine);
	va_end(aptr);
	return (EXIT_SUCCESS);
}

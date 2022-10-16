/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 23:02:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_option(t_machine *machine)
{
	static void		(*actions[])(t_machine *) = {string, character, low_hex, up_hex};
	const char		*input = machine->input;
	const size_t	option_index = get_index(OPTIONS, input[machine->index]);
	const int		fd = machine->fd;

	if (option_index < NBOF_OPTIONS)
		actions[option_index](machine);
	else if (input[machine->index + 1] != '\0')
	{
		ft_putchar_fd(OPTION_CHAR, fd);
		if (input[machine->index + 2] != '\0')
			ft_putchar_fd(input[machine->index], fd);
	}
	machine->state = E_IDLE;
}

static enum e_state	get_next_state(t_machine *machine)
{
	const char	curr_c = (machine->input)[machine->index];
	const int	fd = machine->fd;

	if (curr_c == '\0')
		machine->state = E_END;
	else if (machine->state == E_OPTION)
		get_option(machine);
	else if (curr_c == OPTION_CHAR)
		machine->state = E_OPTION;
	else
		ft_putchar_fd(curr_c, fd);
	++(machine->index);
	return (machine->state);
}

int	ft_vdprintf(int fd, const char *str, va_list aptr)
{
	t_machine	*machine;

	machine = init_machine(str, aptr, fd);
	while (get_next_state(machine) != E_END)
	{
	//	if (machine->state == E_IDLE)
	//		state_action[machine->state](aptr);
	}
	free(machine);
	return (EXIT_SUCCESS);
}

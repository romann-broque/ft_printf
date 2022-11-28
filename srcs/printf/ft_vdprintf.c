/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/28 23:38:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_output(t_machine *machine)
{
	static size_t		(*state_function[])(t_machine *) = {
		standard_state,
		conv_state};
	t_output *const	output = machine->output;

	while (machine->state != E_END)
		machine->input += state_function[machine->state](machine);
	output->final_str = add_str(output->final_str, output->buffer, output->index);
	output->total_size += output->index;
}

int	ft_vdprintf(int fd, const char *str, va_list aptr)
{
	t_machine	*machine;
	ssize_t		ret_val;

	machine = init_machine(str, aptr, fd);
	ret_val = 0;
	if (machine != NULL && machine->output != NULL && machine->arg != NULL)
	{
		get_output(machine);
		ret_val = write(fd, machine->output->final_str, machine->output->total_size);
	}
	free_machine(machine);
	return ((int)ret_val);
}

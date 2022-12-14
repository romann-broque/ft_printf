/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:28:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 21:16:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *str, va_list aptr)
{
	static size_t		(*state_function[])(t_machine *) = {
		standard_state,
		mod_state,
		width_state,
		precision_state,
		conv_state};
	t_machine			*machine;
	ssize_t				ret_val;

	machine = init_machine(str, aptr, fd);
	while (machine->state != E_END)
		machine->input += state_function[machine->state](machine);
	machine->output = ft_strnjoin(machine->output,
			machine->buffer, machine->index + 1);
	ret_val = write(fd, machine->output,
		machine->nbof_buffer * BUFFER_SIZE + machine->index);
	free_machine(machine);
	return (ret_val);
}

/*
// mod

	input_offset = 0;
	if (flag)
		input_offset = add_flag
	else
		state = converter
	return (input_offset);

// converter
	
	function = {conv_s, conv_d, conv_c, ...};

	string = function[](va_list, flags)
	add_to_buffer(string)
	free(string)

// conv_d

	return (conv_numeric(nb, flags, itoa))

// conv_numeric (nb, flags, char *(*function)(long))

	apply_flags()
	function(nb)
	
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:18:25 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/20 15:31:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	apply_converter(t_machine *machine)
{
	static char	*(*conv[])() = {character, string, percentage};
//, low_hex, up_hex, address, integer_d, integer_i, u_integer};
	const char	curr_c = *(machine->input);
	ssize_t		index;
	char		*string;

	index = get_index(OPTIONS, curr_c);
	if (index != -1)
		string = conv[index](machine->arg->aptr);
	else
		string = fill_unknown(machine);
	if (string != NULL)
		cpy_to_buffer(machine, string);
	free(string);
	return (curr_c != '\0');
}

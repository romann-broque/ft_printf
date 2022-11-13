/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:20 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/13 22:51:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_machine *machine)
{
	machine->arg->width = machine->arg->width * 10 + *machine->input - '0';
	machine->state = E_MOD;
}

char	*fill_unknown(t_machine *machine)
{
	char		*string;
	size_t		len;

	len = 0;
	if (machine->input[0] != '\0' && machine->input[1] != '\0')
		len += 1 + (machine->input[2] != '\0');
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string != NULL)
	{
		string[len] = '\0';
		if (len > 0)
			string[0] = *OPTION_CHAR;
		if (len > 1)
			string[1] = *machine->input;
	}
	return (string);
}


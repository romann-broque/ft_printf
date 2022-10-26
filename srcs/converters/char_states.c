/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 16:23:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string(t_machine *machine)
{
	char		*str;

	str = va_arg(machine->aptr, char *);
	if (str == NULL)
		str = NULL_DEF;
	return (ft_strdup(str));
}

char	*character(t_machine *machine)
{
	const int	c = va_arg(machine->aptr, int);

	return (to_string(c));
}

char	*percentage(void)
{
	return (to_string(OPTION_CHAR));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/26 15:47:50 by rbroque          ###   ########.fr       */
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
	char		str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}

char	*percentage(t_machine *machine)
{
	const int	c = '%';

	cpy_data(machine, (char *)&c, sizeof(char));
	return (NULL);
}

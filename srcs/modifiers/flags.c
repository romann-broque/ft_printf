/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:51:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/09 09:56:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(t_machine *machine, const ssize_t flag_index)
{
	ssize_t			i;
	uint8_t			flag;

	flag = NO_FLAG;
	i = 0;
	while (i <= flag_index)
	{
		flag <<= 1;
		++i;
	}
	machine->flags |= flag;
}

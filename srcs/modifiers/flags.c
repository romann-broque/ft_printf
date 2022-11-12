/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:51:00 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 14:30:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remove_flag(t_flag *flags, t_flag removing_flag)
{
	if (*flags & removing_flag)
		*flags ^= removing_flag;
}

void	get_flag(t_flag *flags, const ssize_t flag_index)
{
	ssize_t	i;
	t_flag	flag;

	flag = NO_FLAG;
	i = 0;
	while (i <= flag_index)
	{
		flag <<= 1;
		++i;
	}
	*flags |= flag;
}

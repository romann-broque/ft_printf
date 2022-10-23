/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:19:40 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/23 18:51:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	unit(void)
{
	return (1);
}

static size_t	address_size(void)
{
	return (16);
}

static size_t	get_hexsize(unsigned long nb)
{
	size_t	size;

	size = (nb == 0);
	while (nb > 0)
	{
		nb /= 16;
		++size;
	}
	return (size);
}

static size_t	get_nbsize(long nb)
{
	size_t	size;

	size = (nb <= 0);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

static size_t	get_unbsize(unsigned long nb)
{
	size_t	size;

	size = (nb != 0);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

void	get_widthsize(t_machine *machine, ssize_t option_index)
{
	static size_t	(*get_argsize[])() = {ft_strlen, unit, get_hexsize,
		get_hexsize, address_size, get_nbsize, get_unbsize, get_nbsize, unit};
	size_t	argsize;
	void	*arg;

	arg = va_arg(machine->aptr, void *);
	argsize = get_argsize[option_index](arg);
	if (argsize < machine->width)
		machine->width -= argsize;
	else
		machine->width = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/14 15:58:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define OPTION_CHAR '%'
# define OPTIONS "s"
# define NBOF_OPTIONS 1

enum e_state
{
	E_IDLE,
	E_OPTION,
	E_END,
};

typedef struct s_machine
{
	char			*input;
	size_t			index;
	va_list			aptr;
	enum e_state	state;
}				t_machine;


// ft_printf

int		ft_printf(const char *str, ...);

// machine_struct

t_machine	*init_machine(const char *str, va_list aptr);

// states

void	string(t_machine *machine);

// utils

size_t	get_index(const char *str, const char c);


#endif

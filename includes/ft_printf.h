/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/11 15:59:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define OPTION_CHAR '%'

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
	enum e_state	state;
}				t_machine;


// machine_struct

t_machine	*init_machine(const char *str);

// ft_printf

int		ft_printf(const char *str, ...);

#endif

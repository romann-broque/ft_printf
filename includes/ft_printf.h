/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 20:19:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define HEX "0123456789ABCDEF"
# define OPTION_CHAR '%'
# define OPTIONS "scX"
# define NBOF_OPTIONS 3

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
	int				fd;
	enum e_state	state;
}				t_machine;


// ft_vdprintf

int		ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_printf

int		ft_printf(const char *str, ...);

// machine_struct

t_machine	*init_machine(const char *str, va_list aptr, int fd);

//print_hex

void	ft_puthex_fd(const unsigned long nb, int fd);

// states

void	string(t_machine *machine);
void	character(t_machine *machine);
void	up_hex(t_machine *machine);

// utils

size_t	get_index(const char *str, const char c);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/17 15:13:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# define NULL_DEF "(null)"
# define NIL_DEF "(nil)"
# define PRE_HEX "0x"
# define LOW_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define OPTION_CHAR '%'
# define OPTIONS "scxXpdu%"
# define NBOF_OPTIONS 8

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

int			ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_printf

int			ft_printf(const char *str, ...);

// ft_putunbr_fd

void		ft_putunbr_fd(unsigned int n, int fd);

// machine_struct

t_machine	*init_machine(const char *str, va_list aptr, int fd);

//print_hex

void		ft_puthex_fd(const char *hbase, const unsigned int nb, int fd);
void		ft_putlhex_fd(const char *hbase, const unsigned long nb, int fd);

// states

void		string(t_machine *machine);
void		character(t_machine *machine);
void		low_hex(t_machine *machine);
void		up_hex(t_machine *machine);
void		address(t_machine *machine);
void		integer(t_machine *machine);
void		u_integer(t_machine *machine);
void		percentage(t_machine *machine);

// utils

size_t		get_index(const char *str, const char c);

#endif

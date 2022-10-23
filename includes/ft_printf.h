/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/21 15:08:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define NULL_DEF "(null)"
# define NIL_DEF "(nil)"
# define WIDTH_UNIT " "
# define PRE_HEX "0x"
# define LOW_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define PREFIX_HEX "0x"
# define OPTION_CHAR '%'
# define OPTIONS "scxXpdui%"
# define NBOF_OPTIONS 9

# define FLAGS " +#-"
# define NBOF_FLAGS 4
# define NO_FLAG 0x01
# define SPACE_FLAG 0x02
# define PLUS_FLAG 0x04
# define PREFIX_FLAG 0x08
# define MINUS_FLAG 0x10

enum e_state
{
	E_IDLE,
	E_OPTION,
	E_END,
};

typedef struct s_machine
{
	char			*input;
	va_list			aptr;
	int				fd;
	size_t			width;
	uint8_t			flags;
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

//print

void	print(t_machine *machine, ssize_t option_index);

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
void		integer_ten(t_machine *machine);
void		percentage(t_machine *machine);

// get_size

void	get_widthsize(t_machine *machine, ssize_t option_index);

// utils

ssize_t		get_index(const char *str, const char c);

#endif

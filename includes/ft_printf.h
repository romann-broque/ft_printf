/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/08 17:48:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define NULL_DEF "(null)"
# define NIL_DEF "(nil)"
# define END_CHAR '\0'
# define PLUS_SIGN "+"
# define MINUS_SIGN "+"
# define NIL_DEF "(nil)"
# define WIDTH_UNIT " "
# define PRE_HEX "0x"
# define HEX "0123456789abcdef"
# define DEC "0123456789"
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
	E_STANDARD,
	E_MOD,
	E_CONV,
	E_END,
};

typedef struct s_machine
{
	const char	*input;
	char			*output;
	va_list			aptr;
	char			buffer[BUFFER_SIZE];
	size_t			nbof_buffer;
	size_t			index;
	size_t			width;
	int				fd;
	uint8_t			flags;
	enum e_state	state;
}				t_machine;

// ft_vdprintf

int			ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_printf

int			ft_printf(const char *str, ...);

// machine_struct

t_machine	*init_machine(const char *str, va_list aptr, int fd);

// fill_nb

void		fill_nbr(int n, t_machine *machine);
void		fill_unbr(unsigned int n, t_machine *machine);

//fill_hex

void		fill_hex(const char *hbase, const unsigned int nb, t_machine *machine);
void		fill_lhex(const char *hbase, const unsigned long nb, t_machine *machine);

//states_utils

char		*fill_unknown(t_machine *machine);
void		get_flag(t_machine *machine, const ssize_t flag_index);

// converters

char		*string(va_list aptr);
char		*character(va_list aptr);
char		*low_hex(va_list aptr, int flags);
char		*up_hex(va_list aptr, int flags);
char		*address(va_list aptr, int flags);
char		*integer(va_list aptr, int flags);
char		*u_integer(va_list aptr, int flags);
char		*integer_ten(va_list aptr, int flags);
char		*percentage(void);

// states

size_t		conv_state(t_machine *machine);
size_t		mod_state(t_machine *machine);
size_t		standard_state(t_machine *machine);

// get_size

void		get_widthsize(t_machine *machine, ssize_t option_index);

// tocase_str

char		*toupper_str(char *str);
char		*tolower_str(char *str);

// itoa_base

char		*itoa_base(const unsigned long nb, const char *base);

// get_abs

unsigned int	get_abs(int nb);

// utils

ssize_t		get_index(const char *str, const char c);
void		cpy_data(t_machine *machine, void *data, size_t n);
char		*to_string(const char c);

#endif

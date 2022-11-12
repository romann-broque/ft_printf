/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/12 20:43:12 by rbroque          ###   ########.fr       */
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
# define SPACE_PAT " "
# define END_CHAR '\0'
# define PLUS_SIGN "+"
# define MINUS_SIGN "-"
# define NIL_DEF "(nil)"
# define WIDTH_UNIT " 0"
# define HEX "0123456789abcdef"
# define DEC "0123456789"
# define PREFIX_HEX "0x"
# define OPTION_CHAR '%'
# define OPTIONS "cs%diupxX"
# define NBOF_OPTIONS 9

# define FLAGS " +#-0"
# define NBOF_FLAGS 4
# define NO_FLAG 0x01
# define SPACE_FLAG 0x02
# define PLUS_FLAG 0x04
# define PREFIX_FLAG 0x08
# define MINUS_FLAG 0x10
# define ZERO_FLAG 0x20

# define CHAR_TYPE 0x0007
# define NB_TYPE 0x01F8
# define SIGNED_TYPE 0x0018
# define UNSIGNED_TYPE 0x01E0
# define HEX_TYPE 0x01C0

enum e_state
{
	E_STANDARD,
	E_MOD,
	E_CONV,
	E_END,
};

typedef uint16_t t_type;
typedef uint8_t t_flag;

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
	t_flag			flags;
	enum e_state	state;
}				t_machine;

// ft_vdprintf

int			ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_printf

int			ft_printf(const char *str, ...);

// machine_struct

t_machine	*init_machine(const char *str, va_list aptr, int fd);
void		free_machine(t_machine *machine);

//states_utils

char		*fill_unknown(t_machine *machine);

// converters

size_t		apply_converter(t_machine *machine);
char		*character_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width);
char		*nb_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width);
char		*signed_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width);
char		*unsigned_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width);
char		*hex_conv(t_type curr_type, va_list aptr, t_flag *flags, size_t width);

char		*character(va_list aptr);
char		*string(va_list aptr);
char		*percentage(void);
char		*low_hex(va_list aptr, t_flag *flags);
char		*up_hex(va_list aptr, t_flag *flags);
char		*address(va_list aptr, t_flag *flags);
char		*integer_d(va_list aptr, t_flag *flags);
char		*integer_i(va_list aptr, t_flag *flags);
char		*u_integer(va_list aptr);

// states

size_t		conv_state(t_machine *machine);
size_t		mod_state(t_machine *machine);
size_t		standard_state(t_machine *machine);

// flags

void		remove_flag(t_flag *flags, t_flag removing_flag);
size_t		get_index_from_type(t_type type, t_type mask);
void		get_flag(t_flag *flags, const ssize_t flag_index);

// get_size

void		get_widthsize(t_machine *machine, ssize_t option_index);

// tocase_str

char		*toupper_str(char *str);
char		*tolower_str(char *str);

// itoa_base

size_t		get_nbsize(unsigned long nb, const size_t len_base);
char		*itoa_base(const unsigned long nb, const char *base);

// get_abs

unsigned int	get_abs(int nb);

// utils

ssize_t		get_index(const char *str, const char c);
char		*to_string(const char c);

// strings

char	*strset(int c, size_t n);

// cpy_data

void		cpy_data(t_machine *machine, void *data, size_t n);
void		cpy_to_buffer(t_machine *machine, char *string, int type);

#endif

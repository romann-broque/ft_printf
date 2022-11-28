/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/29 00:28:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define EMPTY_STRING ""
# define NULL_DEF "(null)"
# define NIL_DEF "(nil)"
# define SPACE_PAT " "
# define END_CHAR '\0'
# define MINUS_SIGN "-"
# define HEX "0123456789abcdef"
# define DEC "0123456789"
# define PREFIX_HEX "0x"
# define OPTION_CHAR "%"
# define CONVERTERS "cs%diuxXp"

# define NO_TYPE 0x0000
# define CHAR_TYPE 0x0007
# define CHARACTER_TYPE 0x0001
# define NB_TYPE 0x01F8
# define SIGNED_TYPE 0x0018
# define UNSIGNED_TYPE 0x01E0
# define HEX_TYPE 0x01C0
# define LOW_TYPE 0x0040
# define UP_TYPE 0x0080
# define ADDRESS_TYPE 0x0100

enum e_state
{
	E_STANDARD,
	E_CONV,
	E_END,
};

typedef uint16_t	t_type;

typedef struct s_arg
{
	va_list	aptr;
	t_type	type;
}				t_arg;

typedef struct s_output
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	index;
	size_t	total_size;
	char	*final_str;
}				t_output;

typedef struct s_machine
{
	const char		*input;
	t_output		*output;
	t_arg			*arg;
	int				fd;
	enum e_state	state;
}				t_machine;

// ft_vdprintf

int			ft_vdprintf(int fd, const char *str, va_list aptr);

// ft_printf

int			ft_printf(const char *str, ...);

// machine_struct

t_arg		*init_arg(t_type type, va_list aptr);
t_machine	*init_machine(const char *str, va_list aptr, int fd);
void		free_machine(t_machine *machine);

//states_utils

char		*fill_unknown(t_machine *machine);

// converters

size_t		apply_converter(t_machine *machine);
char		*character(va_list aptr);
char		*string(va_list aptr);
char		*percentage(void);
char		*integer_d(va_list aptr);
char		*integer_i(va_list aptr);
char		*u_integer(va_list nb);
char		*low_hex(va_list aptr);
char		*up_hex(va_list nb);
char		*address(va_list nb);

// states

size_t		conv_state(t_machine *machine);
size_t		standard_state(t_machine *machine);

// itoa_base

char		*itoa_base(const unsigned long nb, const char *base);

// get_nb_data

uint		get_abs(int nb);

// strings

char		*add_str(char *s1, const char *s2, const size_t n);
char		*ft_strndup(const char *str, const size_t size);
ssize_t		get_index(const char *str, const char c);
char		*to_string(const char c);
char		*toupper_str(char *str);

// cpy_data

void		cpy_data(t_output *output, void *data, size_t n);
void		cpy_to_buffer(t_machine *machine, char *string);

#endif

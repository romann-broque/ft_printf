# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 23:52:41 by rbroque           #+#    #+#              #
#    Updated: 2022/11/28 23:56:48 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = libftprintf.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/converters/
PATH_SRCS += srcs/converters/type
PATH_SRCS += srcs/struct/
PATH_SRCS += srcs/modifiers/
PATH_SRCS += srcs/printf/
PATH_SRCS += srcs/states/
PATH_SRCS += srcs/utils/

# srcs/

# srcs/converters
SRCS += apply_converter.c
SRCS += char_conv.c
SRCS += hex_conv.c
SRCS += nb_conv.c

# srcs/converters/type

# srcs/struct
SRCS += machine_struct.c

# srcs/printf
SRCS += ft_printf.c
SRCS += ft_vdprintf.c

# srcs/states
SRCS += states.c
SRCS += states_utils.c

# srcs/utils
SRCS += strings.c
SRCS += tocase_str.c
SRCS += itoa_base.c
SRCS += cpy_data.c
SRCS += get_nb_data.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### LIB

LIB_FOLDER = libft/
LIB = $(LIB_FOLDER)/libft.a

### INCLUDES

INCLUDES += includes/
INCLUDES_LIB = $(LIB_FOLDER)/includes/
HEADER = $(INCLUDES)/ft_printf.h

### COMPILATION

CC = cc

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -fPIE

LINKS += -lft

ifneq ($(noerror), 1)
	CFLAGS += -Werror
endif

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

### RULES

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIB):
	$(MAKE) -sC $(LIB_FOLDER)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(INCLUDES_LIB)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIB_FOLDER) fclean

re: fclean
	$(MAKE)

norm:
	@norminette $(PATH_SRCS) $(INCLUDES) $(LIB_FOLDER)

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:35:01 by rbroque           #+#    #+#              #
#    Updated: 2022/11/14 17:07:39 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = libftprintf.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/converters/
PATH_SRCS += srcs/converters/type
PATH_SRCS += srcs/core/
PATH_SRCS += srcs/core/struct/
PATH_SRCS += srcs/modifiers/
PATH_SRCS += srcs/printf/
PATH_SRCS += srcs/states/
PATH_SRCS += srcs/utils/

# srcs/

SRCS += width.c
SRCS += precision.c

# srcs/converters
SRCS += apply_converter.c
SRCS += char_states.c
SRCS += hex_states.c
SRCS += int_states.c

# srcs/converters/type
SRCS += character_type.c
SRCS += nb_type.c
SRCS += signed_type.c
SRCS += unsigned_type.c
SRCS += hex_type.c

# srcs/core
# srcs/core/struct
SRCS += machine_struct.c

# srcs/modifiers
SRCS += flags.c

# srcs/printf
SRCS += ft_printf.c
SRCS += ft_vdprintf.c

# srcs/states
SRCS += states.c
SRCS += states_utils.c

# srcs/utils
SRCS += utils.c
SRCS += strings.c
SRCS += tocase_str.c
SRCS += itoa_base.c
SRCS += get_abs.c
SRCS += cpy_data.c

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

### CHECK

CHECK_FOLDER = tests/

### COMPILATION

CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -fPIE

LINKS += -lft

ifneq ($(noerror), 1)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
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

test: $(NAME)
	$(MAKE) -sC $(CHECK_FOLDER) $(IS_BONUS)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean
	$(MAKE) -sC $(CHECK_FOLDER) fclean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIB_FOLDER) fclean
	$(MAKE) -sC $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

norm:
	@norminette $(PATH_SRCS) $(INCLUDES)

.PHONY: all clean fclean re

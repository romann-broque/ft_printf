# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:35:01 by rbroque           #+#    #+#              #
#    Updated: 2022/10/10 16:56:03 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = libftprintf.a

### SRCS

PATH_SRCS += srcs/

#SRCS += main.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### LIB

LIB_FOLDER = libft/
LIB_HEADER = $(LIB_FOLDER)/includes/libft.h
LIB = $(LIB_FOLDER)/libft.a

### INCLUDES

INCLUDES += includes/
INCLUDES += $(LIB_HEADER)

### CHECK

CHECK_FOLDER = tests/

### COMPILATION

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra

ifneq ($(noerror), 1)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
endif

### RULES

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	ar rcs $@ $^

$(LIB):
	$(MAKE) -sC $(LIB_FOLDER)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -L $(LIB)

test: $(NAME)
	$(MAKE) -sC $(CHECK_FOLDER) $(IS_BONUS)
#	$(CHECK_FOLDER)/run_tests.sh $(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean
	$(MAKE) -sC $(CHECK_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIB_FOLDER) fclean
	$(MAKE) -sC $(CHECK_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

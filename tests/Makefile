# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/10/10 16:49:03 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += srcs/

# main

CHECK_SRCS += main.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_CHECK_OBJS += objs

CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(CHECK_SRCS))

########## INCLUDES

CHECK_INCLUDES += /usr/include
TEST_INCLUDES += includes/
INCLUDES += ../includes

########## INCLUDES

LIB += /usr/lib/aarch64-linux-gnu/libcheck.a # Must be changed according with the OS
LIB += ../libft/libft.a

vpath %.h $(INCLUDES)
vpath %test.h $(TEST_INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

LINKS += -lcheck
LINKS += -lbsd
LINKS += -lsubunit
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIB) $(LINKS) -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES)
	@echo $(NAME) COMPILED !

$(CHECK_OBJS): $(PATH_CHECK_OBJS)/%.o: %.c
	mkdir -p $(PATH_CHECK_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES) -I $(TEST_INCLUDES)

clean:
	$(RM) -R $(PATH_CHECK_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

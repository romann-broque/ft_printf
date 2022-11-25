# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/11/25 15:52:51 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests/exe

########## SRCS

PATH_SRCS += srcs/
PATH_SRCS += tests/

# CHECKS

CHECK_SRCS += main.c
CHECK_SRCS += character.test.c
CHECK_SRCS += string.test.c
CHECK_SRCS += percentage.test.c
CHECK_SRCS += integer.test.c
CHECK_SRCS += integer_ten.test.c
CHECK_SRCS += u_integer.test.c
CHECK_SRCS += low_hex.test.c
CHECK_SRCS += up_hex.test.c
CHECK_SRCS += address.test.c

# FINAL_SRCS

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_CHECK_OBJS += objs

CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(CHECK_SRCS))

########## INCLUDES

CHECK_INCLUDES += /usr/include/
TEST_INCLUDES += includes/
INCLUDES += ../includes/
LIB_INCLUDES += ../libft/includes

vpath %.h $(INCLUDES)
vpath %test.h $(TEST_INCLUDES)

########## LIB

LIB += -L ../ -lftprintf
LIB += -L ../libft/ -lft

########## COMPILER

CC = cc 

CFLAGS += -Wno-format-security
CFLAGS += -fPIE
#CFLAGS += -Wall
#CFLAGS += -Wextra
#CFLAGS += -Werror

LINKS += -lbsd
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)
	./tests/exe_test.sh ./tests/exe

$(NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) $(LINKS) -o $@ -I $(LIB_INCLUDES) -I $(INCLUDES) -I $(CHECK_INCLUDES)
	@echo $(NAME) COMPILED !

$(CHECK_OBJS): $(PATH_CHECK_OBJS)/%.o: %.c
	@mkdir -p $(PATH_CHECK_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES) -I $(TEST_INCLUDES)

clean:
	$(RM) -R $(PATH_CHECK_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

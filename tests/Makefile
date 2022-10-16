# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:14:45 by rbroque           #+#    #+#              #
#    Updated: 2022/10/16 22:59:46 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests/exe
FINAL_NAME = tests/is_same

########## SRCS

PATH_SRCS += srcs/
PATH_SRCS += tests/

# CHECKS

CHECK_SRCS += main.c
CHECK_SRCS += string.test.c
CHECK_SRCS += character.test.c
CHECK_SRCS += low_hex.test.c
CHECK_SRCS += up_hex.test.c

# FINAL_SRCS

FINAL_CHECK_SRCS += is_same_output.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_CHECK_OBJS += objs

CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(CHECK_SRCS))
FINAL_CHECK_OBJS += $(patsubst %.c, $(PATH_CHECK_OBJS)/%.o, $(FINAL_CHECK_SRCS))

########## INCLUDES

CHECK_INCLUDES += /usr/include/
TEST_INCLUDES += includes/
INCLUDES += ../includes/
LIB_INCLUDES += ../libft/includes

vpath %.h $(INCLUDES)
vpath %test.h $(TEST_INCLUDES)

########## LIB

LIB += -L /usr/lib/aarch64-linux-gnu/libcheck.a # Must be changed according with the OS
LIB += -L ../ -lftprintf
LIB += -L ../libft/ -lft

########## COMPILER

CC = clang

CFLAGS += -Wno-format-security
#CFLAGS += -Wall
#CFLAGS += -Wextra
#CFLAGS += -Werror

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

all: $(NAME) $(FINAL_NAME)
	./tests/exe_test.sh ./tests/exe

$(FINAL_NAME): $(FINAL_CHECK_OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) $(LINKS) -o $@ -I $(LIB_INCLUDES) -I $(INCLUDES) -I $(CHECK_INCLUDES)

$(FINAL_CHECK_OBJS): $(PATH_CHECK_OBJS)/%.o: %.c
	@mkdir -p $(PATH_CHECK_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(CHECK_INCLUDES) -I $(TEST_INCLUDES)

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
	$(RM) $(FINAL_NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

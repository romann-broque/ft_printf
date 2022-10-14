# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/10/14 21:02:38 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = libft.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/ctype
PATH_SRCS += srcs/gnl
PATH_SRCS += srcs/list
PATH_SRCS += srcs/memory
PATH_SRCS += srcs/output
PATH_SRCS += srcs/strings

# ctype

SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# list

SRCS_BONUS += ft_lstadd_back.c
SRCS_BONUS += ft_lstadd_front.c
SRCS_BONUS += ft_lstclear.c
SRCS_BONUS += ft_lstdelone.c
SRCS_BONUS += ft_lstiter.c
SRCS_BONUS += ft_lstlast.c
SRCS_BONUS += ft_lstmap.c
SRCS_BONUS += ft_lstnew.c
SRCS_BONUS += ft_lstsize.c

# memory

SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c

# output

SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c

# strings

SRCS += ft_atoi.c
SRCS += ft_itoa.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c

# gnl

SRCS += get_next_line.c
SRCS += get_next_line_utils.c

ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
	SRCS += $(SRCS_BONUS)
else ifeq (test, $(findstring test, $(MAKECMDGOALS)))
	SRCS += $(SRCS_BONUS)
endif

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES += includes/

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

bonus: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all bonus clean fclean re
.SILENT: bonus

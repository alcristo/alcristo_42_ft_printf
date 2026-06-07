# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 09:17:08 by alcristo          #+#    #+#              #
#    Updated: 2026/06/07 10:48:15 by alcristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SOURCES= 	ft_printf.c							\
			ft_printf_putchar.c					\
			ft_printf_putstr.c					\
			ft_printf_putnbr.c					\
			ft_printf_putuns.c					\
			ft_printf_puthex.c					\
			ft_printf_putmem.c					\
			ft_printf_putmem.c					\
			ft_printf_flags.c					\
			ft_printf_putchar_opts.c			\
			ft_printf_putstr_opts.c				\
			ft_printf_putnbr_opts.c				\
			ft_printf_nbr_padtoleft.c			\
			ft_printf_putuns_opts.c				\
			ft_printf_puthex_opts.c				\
			ft_printf_hex_padtoleft.c			\
			ft_printf_putmem_opts.c				\
			ft_atoi.c							\
			ft_isdigit.c						\
			ft_strchr.c							\

OBJECTS= $(SOURCES:.c=.o)

HEADER= ft_printf.h

CC= cc

CFLAGS= -Wall -Werror -Wextra

AR= ar -rcs

RM= rm -f

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

#$(OBJECTS):
#	$(CC) $(FLAGS) -o $(OBJECTS) $(SOURCES)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

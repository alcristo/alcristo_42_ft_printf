# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 09:17:08 by alcristo          #+#    #+#              #
#    Updated: 2026/06/24 09:16:30 by alcristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SOURCES= 	srcs/ft_printf.c							\
			srcs/ft_printf_putchar.c					\
			srcs/ft_printf_putstr.c						\
			srcs/ft_printf_putnbr.c						\
			srcs/ft_printf_putuns.c						\
			srcs/ft_printf_puthex.c						\
			srcs/ft_printf_putmem.c						\
			srcs/ft_printf_putflt.c						\
			srcs/ft_printf_flags.c						\
			srcs/ft_printf_putchar_opts.c				\
			srcs/ft_printf_putstr_opts.c				\
			srcs/ft_printf_putnbr_opts.c				\
			srcs/ft_printf_nbr_padtoleft.c				\
			srcs/ft_printf_putuns_opts.c				\
			srcs/ft_printf_puthex_opts.c				\
			srcs/ft_printf_hex_padtoleft.c				\
			srcs/ft_printf_putmem_opts.c				\
			srcs/ft_printf_putflt_opts.c				\
			srcs/ft_atoi.c								\
			srcs/ft_isdigit.c							\
			srcs/ft_strchr.c							\
			srcs/ft_power.c								\

OBJECTS= $(SOURCES:.c=.o)

#HEADER= srcs/includes/ft_printf.h

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

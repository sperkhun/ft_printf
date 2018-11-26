#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:59:28 by sperkhun          #+#    #+#              #
#    Updated: 2018/11/21 16:59:29 by sperkhun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ./srcs/ft_printf.c ./srcs/parse_format.c ./srcs/validate.c\
		./srcs/define_specifier.c ./srcs/print_types.c ./srcs/num_to_str.c\
		./srcs/putnumbers.c ./srcs/ft_memcpy.c ./srcs/ft_strlen.c\
		./srcs/ft_strchr.c ./srcs/ft_atoi.c ./srcs/ft_isdigit.c\
		./srcs/ft_strnew.c ./srcs/ft_strdel.c ./srcs/ft_itoa.c\
		./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_bzero.c\
		./srcs/ft_isspace.c ./srcs/ft_strdup.c ./srcs/ft_memset.c\
		./srcs/ft_strcmp.c ./srcs/ft_strequ.c ./srcs/print_decimal.c\
		./srcs/print_unsigned.c

OBJ = $(SRC:.c=.o)

INCL = -I ./includes/

%.o: %.c ./includes/ft_printf.h ./includes/libft.h
	@gcc $(FLAGS) -c $< -o $@ $(INCL)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Creating $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
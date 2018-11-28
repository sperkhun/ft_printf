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
		./srcs/define_specifier.c ./srcs/parse_cspf.c ./srcs/num_to_str.c\
		./srcs/parse_decimal.c ./srcs/parse_unsigned.c ./srcs/print_csf.c\
		./srcs/print_pdoux.c ./srcs/libft/ft_memcpy.c ./srcs/libft/ft_strlen.c\
		./srcs/libft/ft_strchr.c ./srcs/libft/ft_atoi.c\
		./srcs/libft/ft_isdigit.c ./srcs/libft/ft_strnew.c\
		./srcs/libft/ft_strdel.c ./srcs/libft/ft_itoa.c\
		./srcs/libft/ft_putchar.c ./srcs/libft/ft_putstr.c\
		./srcs/libft/ft_bzero.c ./srcs/libft/ft_isspace.c\
		./srcs/libft/ft_strdup.c ./srcs/libft/ft_memset.c\
		./srcs/libft/ft_strcmp.c ./srcs/libft/ft_strequ.c\

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 15:07:19 by sunakim           #+#    #+#              #
#    Updated: 2019/01/28 16:30:01 by sunakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	./ft_memset.c ./ft_bzero.c ./ft_strcmp.c	\
		./ft_memcpy.c ./ft_strlen.c		\
	  	./ft_memalloc.c ./ft_memdel.c ./ft_strcpy.c\
		./ft_atoi.c ./ft_putstr.c ./ft_strchr.c ./ft_strcpy_no_end.c\
		./ft_strdup.c  \
		./parsing.c		\
	  	./ft_output.c	\
	  	./ft_printf.c	\
		./ft_error.c	\
		./ft_excep.c 	\
		./flags_init.c \
		./ft_ditoa.c ./ft_otoa.c ./ft_utoa.c ./ft_xtoa.c ./ft_char.c	\
		./ft_string.c ./ft_pointer.c ./ft_float.c ./ft_power.c 		\
		./ft_divar.c ./ft_ovar.c ./ft_uvar.c ./ft_xvar.c ./ft_rounding.c	\
		./ft_double_sharp.c

OBJ = 	$(SRC:.c=.o)

HEADER = -I ./

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		gcc -c $(FLAGS) $(SRC) $(HEADER)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

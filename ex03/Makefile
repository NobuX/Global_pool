# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 18:02:39 by pcarre            #+#    #+#              #
#    Updated: 2015/12/10 18:02:54 by pcarre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ./ft_hexdump.c
NAME	= ft_hexdump
OBJ		= ft_hexdump.o

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

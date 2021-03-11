# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 08:16:48 by lmurray           #+#    #+#              #
#    Updated: 2021/03/11 08:27:56 by lmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH=	checker
PS=	push_swap
LIBFT_DIR = ./src/libft/

SRC = src/operations/*.c src/parse/*
SRC_CH = src/checker/checker.c
SRC_SP = src/push_swap/*.c

OBJ_CH = $(SRC_CH:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)

all:	LIBFT $(CH) $(PS)

LIBFT: 
	make re -C ./src/libft/

$(CH):
	gcc -Wall -Werror -Wextra -c $(SRC_CH) $(SRC)
	gcc -o $(CH) $(OBJ_CH) -L. $(LIBFT_DIR)
$(PS):
	gcc -Wall -Werror -Wextra -c $(SRC_PS)
	gcc -o $(PS) $(OBJ_PS) -L. $(LIBFT_DIR)
clean:
	rm -f *.o
fclean:	clean
	rm -f $(CH)
	rm -f $(PS)
re:	fclean all

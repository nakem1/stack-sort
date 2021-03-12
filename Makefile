# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 08:16:48 by lmurray           #+#    #+#              #
#    Updated: 2021/03/11 20:48:40 by lmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
CH=	checker
PS=	push_swap
LIBFT = ./src/libft/libft.a

SRC_CH = ./src/checker/checker.c
SRC_PS = ./src/push_swap/find_optimal.c ./src/push_swap/handler_elems.c \
		./src/push_swap/handler_elems_utils.c \
		./src/push_swap/more_five_hundred_elem.c \
		./src/push_swap/more_hundred_elem.c \
		./src/push_swap/more_three_elem.c ./src/push_swap/push_swap.c

SRC = ./src/operations/push.c ./src/operations/reverse_rotate.c \
		./src/operations/rotate.c ./src/operations/swap.c ./src/parse/parse.c

all:	$(LIBFT) $(CH) $(PS)

$(LIBFT):
	make -C ./src/libft/
	@cowsay "LIBFT IS READY MOOOOOOOO"
	@echo "\n"

$(CH): $(SRC) $(SRC_CH)
	@cowsay -f tux "CHECKER WELL DONE!"
	@$(GCC) -Wall -Werror -Wextra -o $(CH) $(SRC_CH) $(SRC) $(LIBFT)
	@echo "\n"
$(PS): $(SRC) $(SRC_PS)
	@cowsay -f dragon "EEEEEEE PUSH_SWAP IS READY"
	@$(GCC) -Wall -Werror -Wextra -o $(PS) $(SRC_PS) $(SRC) $(LIBFT)
	@echo "\n"
clean:
	@make clean -C ./src/libft/

fclean:	clean
	@rm -f $(CH)
	@rm -f $(PS)
	@make fclean -C ./src/libft/

cowsay:
	brew install cowsay

re:	fclean all

.PHONY: clean fclean all re cowsay

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 20:04:19 by lmurray           #+#    #+#              #
#    Updated: 2021/04/25 15:03:53 by lmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -g3
CH=	checker
PS=	push_swap
LIBFT = ./src/libft/libft.a

MAIN_CH = ./src/checker/main_checker.c
MAIN_PS = ./src/push_swap/main_push_swap.c
MAIN_BONUS = ./src/main_bonus.c
SRC_CH = ./src/checker/checker.c
SRC_PS = ./src/push_swap/find_optimal.c ./src/push_swap/handler_elems.c \
		./src/push_swap/handler_elems_utils.c \
		./src/push_swap/more_five_hundred_elem.c \
		./src/push_swap/more_hundred_elem.c \
		./src/push_swap/more_six_elems.c ./src/push_swap/push_swap.c \
		./src/push_swap/optimization.c ./src/push_swap/optimization_utils.c

SRC = ./src/operations/push.c ./src/operations/reverse_rotate.c \
		./src/operations/rotate.c ./src/operations/swap.c ./src/parse/parse.c \
		./src/parse/parse_utils.c

all:	$(LIBFT) $(CH) $(PS)

$(LIBFT):
	make -C ./src/libft/
	@cowsay "LIBFT IS READY MOOOOOOOO"
	@echo "\n"

$(CH): $(SRC) $(SRC_CH)
	@cowsay -f tux "CHECKER WELL DONE!"
	@$(GCC) -Wall -Werror -Wextra -o $(CH) $(MAIN_CH) $(SRC_CH) $(SRC) $(LIBFT) -I ./includes
	@echo "\n"
$(PS): $(SRC) $(SRC_PS)
	@cowsay -f dragon "EEEEEEE PUSH_SWAP IS READY"
	@$(GCC) -Wall -Werror -Wextra -o $(PS) $(MAIN_PS) $(SRC_PS) $(SRC) $(LIBFT) -I ./includes
	@echo "\n"
clean:
	@make clean -C ./src/libft/

bonus: $(LIBFT)
	@cowsay -f milk "IT's a BONUSSS"
	@$(GCC) -Wall -Werror -Wextra -o bonus $(MAIN_BONUS) $(SRC_CH) $(SRC_PS) $(SRC) $(LIBFT)
	@echo "\n"

fclean:	clean
	@rm -f $(CH)
	@rm -f $(PS)
	@make fclean -C ./src/libft/

cowsay:
	brew install cowsay

re:	fclean all

.PHONY: clean fclean all re cowsay bonus

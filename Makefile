# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 08:16:48 by lmurray           #+#    #+#              #
#    Updated: 2021/03/11 14:49:15 by lmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -g3
CH=	checker
PS=	push_swap
LIBFT_DIR = ./src/libft/
DIR_CH = ./src/checker/
DIR_PS = ./src/push_swap/
DIR_OP = ./src/operations/
DIR_PARSE = ./src/parse/

SRC_OP = push.c reverse_rotate.c rotate.c swap.c
SRC_PAR = parse.c
SRC_CH = checker.c
SRC_PS = find_optimal.c handler_elems.c handler_elems_utils.c more_five_hundred_elem.c more_hundred_elem.c \
		more_three_elem.c push_swap.c

OBJ_CH = $(SRC_CH:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)
OBJ_OP = $(SRC_OP:.c=.o)
OBJ_PAR = $(SRC_PAR:.c=.o)

all:	LIBFT $(CH) $(PS)

LIBFT: 
	make -C ./src/libft/
	@cowsay "LIBFT IS READY MOOOOOOOO"
	@echo "\n"


$(CH):
	@cowsay -f tux "CHECKER WELL DONE!"
	@$(GCC) -Wall -Werror -Wextra -c $(addprefix $(DIR_CH), $(SRC_CH))  $(addprefix $(DIR_OP), $(SRC_OP)) $(addprefix $(DIR_PARSE), $(SRC_PAR))
	@$(GCC) -o $(CH) $(OBJ_CH) $(OBJ_OP) $(OBJ_PAR) $(addprefix $(LIBFT_DIR), libft.a)
	@echo "\n"
$(PS):
	@cowsay -f dragon "EEEEEEE PUSH_SWAP IS READY"
	@$(GCC) -Wall -Werror -Wextra -c $(addprefix $(DIR_PS), $(SRC_PS)) $(addprefix $(DIR_OP), $(SRC_OP)) $(addprefix $(DIR_PARSE), $(SRC_PAR))
	@$(GCC) -o $(PS) $(OBJ_PS) $(OBJ_OP) $(OBJ_PAR) $(addprefix $(LIBFT_DIR), libft.a)
	@echo "\n"
clean:
	@rm -f *.o
	@make clean -C ./src/libft/

fclean:	clean
	@rm -f $(CH)
	@rm -f $(PS)
	@make fclean -C ./src/libft/

cowsay:
	brew install cowsay

re:	fclean all

.PHONY: clean fclean all re cowsay

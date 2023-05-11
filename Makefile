# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 21:44:13 by jalves-c          #+#    #+#              #
#    Updated: 2023/05/11 21:44:42 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	mlxtest
CC		=	@gcc
FLAGS	=	-Wall -Wextra -Werror -fsanitize=address 
LFT		=	libft/libft.a
MLX 	=	mlx/libmlx.a
INC		=	-I ./libft -I ./mlx
LIB		=	-L ./libft -lft -L ./mlx -framework Cocoa -framework OpenGL -framework IOKit
SRC		=	$(wildcard src/*.c)
OBJ		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

#COLORS
RED =		\033[0;31m
GREEN =		\033[0;32m
YELLOW =	\033[0;33m
RESET =		\033[0m


all:		$(MLX) $(LFT) obj $(NAME) #norm

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo "$(YELLOW) [ .. ] | Compiling minilibx...$(RESET)"
			@make -s -C mlx
			@echo "$(GREEN) [ OK ] | Minilibx ready!$(RESET)"

$(LFT):		
			@echo "$(YELLOW) [ .. ] | Compiling libft...$(RESET)"
			@make -s -C libft
			@echo "$(GREEN) [ OK ] | Libft ready!$(RESET)"

obj:
			@mkdir -p obj

obj/%.o: 	src/%.c
			@mkdir -p $(dir $@)
			$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -sC libft clean
			@make -sC mlx clean
			@rm -rf $(OBJ) obj
			@echo "$(GREEN) [ OK ] | Object files removed.$(RESET)"

fclean:		clean
			@make -sC libft fclean
			@rm -rf $(NAME)
			@echo "$(GREEN) [ OK ] | binary file removed.$(RESET)"

re:			fclean all #add norm before all

norm :
			norminette src include
			@echo "$(GREEN) [ OK ] | Norminette.$(RESET)"

.PHONY:		all clean fclean re


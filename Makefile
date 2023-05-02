# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c <jalves-c@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:43:26 by jalves-c          #+#    #+#              #
#    Updated: 2023/05/02 16:52:34 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mlxtest
CC		=	@gcc
FLAGS	=	-Wall -Wextra -Werror
LFT		=	libft/libft.a
MLX		=	minilibx-linux/Makefile.gen
INC		=	-I ./libft -I ./minilibx-linux
LIB		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
SRC		=	$(wildcard src/*.c)
OBJ		= 	$(patsubst src/%.c,obj/%.o,$(SRC))



all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):

			@echo "\033[0;33m  [ .. ] | Compiling minilibx..\033"
			@make -s -C minilibx-linux
			@echo "\033[0;32m [ OK ] | Minilibx ready!\033[0m"

$(LFT):		
			@echo "\033[0;33m [ .. ] | Compiling libft..\033"
			@make -s -C libft
			@echo "\033[0;32m [ OK ] | Libft ready!\033[0m"

obj:
			@mkdir -p obj

obj/%.o: 	src/%.c
			@mkdir -p $(dir $@)
			$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -sC libft clean
			@rm -rf $(OBJ) obj
			@echo "\033[0;32m [ OK ] | Object files removed.\033[0m"

fclean:		clean
			@make -sC libft fclean
			@rm -rf $(NAME)
			@echo "\033[0;32m [ OK ] | binary file removed.\033[0m"

re:			fclean all #norm before all

#norm :
#			@norminette src/
#		@echo "\033[0;32mNorminette: OK!\033[0m"

.PHONY:		all clean fclean
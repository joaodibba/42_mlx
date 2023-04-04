# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 11:37:14 by helferna          #+#    #+#              #
#    Updated: 2023/04/04 20:41:05 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	mlxtest
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	libft/libft.a
OBJ			= 	$(patsubst src/%.c,obj/%.o,$(SRC))
SRC			=	$(wildcard src/*.c)
MLX			=	minilibx-linux/Makefile.gen
INC			=	-I ./libft -I ./minilibx-linux
LIB			=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd



all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C minilibx-mac-osx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
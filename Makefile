# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:29:34 by jalves-c          #+#    #+#              #
#    Updated: 2023/05/11 23:22:36 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mlxteste
CC		=	@gcc
FLAGS	=	-Wall -Wextra -Werror -fsanitize=address 
LFT		=	libft/libft.a
MLX 	=	mlx/libmlx.a
INC		=	-I ./libft -I ./mlx
SRC		=	$(wildcard src/*.c)
OBJ		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

ifeq ($(UNAME), Darwin)
	LIB		=	-L ./libft -lft -L ./mlx -framework OpenGL -framework AppKit
else
	LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

		
endif

#COLORS
RED =		\033[0;31m
GREEN =		\033[0;32m
YELLOW =	\033[0;33m
RESET =		\033[0m


all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling mlxteste..."
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "[" "$(GREEN)OK$(RESET)" "] | mlxteste ready!"

$(MLX):
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
			@make -sC mlx > /dev/null 2>&1
			@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

$(LFT):		
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
			@make -sC libft
			@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o: 	src/%.c
			@mkdir -p $(dir $@)
			$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -sC libft clean
			@make -sC mlx clean > /dev/null
			@rm -rf $(OBJ) obj
			@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean:		clean
			@make -sC libft fclean
			@rm -rf $(NAME)
			@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

re:			fclean norm all

norm:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Running Norminette...$(RESET)"
	@if norminette src include | grep -q "Error!"; then \
		echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
		norminette src include | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	else \
		echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	fi


.PHONY:		all clean fclean re

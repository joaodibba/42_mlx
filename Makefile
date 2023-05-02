# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 11:37:14 by helferna          #+#    #+#              #
#    Updated: 2023/05/02 16:32:33 by jalves-c         ###   ########.fr        #
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

# Add dependency on the obj target to ensure that the obj directory exists
all: $(MLX) $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C minilibx-linux
			@echo " [ OK ] | Minilibx ready!"

$(LFT):
	@echo " [ .. ] | Compiling libft.."
	@make -s -C libft
	@echo " [ OK ] | Libft ready!"

# Create obj directory if it doesn't exist
obj:
	@mkdir -p obj

# Create object files in obj/ directory
obj/%.o: src/%.c | obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -s $@ -C libft
	# Remove the obj directory along with its contents
	@rm -rf obj
	@echo "object files removed."

fclean: clean
	@make -s $@ -C libft
	# Remove the binary file
	@rm -rf $(NAME)
	@echo "binary file removed."

re: fclean all

.PHONY: all clean fclean re obj

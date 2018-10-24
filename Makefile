# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 19:09:46 by amasol            #+#    #+#              #
#    Updated: 2018/10/17 19:09:48 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
#FLAGS = -Wall -Wextra -Werror
LIB = libft.a
SRC = main.c ft_size_list.c error.c save_map.c ft_atoi_fdf.c print_fdf.c mogify_coords.c tttt.c
MLX := -lmlx -framework OpenGL -framework AppKit

HEADERS = ./fdf.h
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	echo "-----------------------------------"
	echo "FdF is ready to work"
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc -g $(OBJ) $(LIB) $(MLX) $(FLAGS) -o $(NAME)
%.o: %.c $(HEADERS)
	@ gcc $(FLAGS) -c $<
clean:
	echo "-----------------------------------"
	echo "Objects files are removed"
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean
fclean: clean
	echo "-----------------------------------"
	echo "FdF is deleted"
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ cd ./libft && make fclean
re: fclean all

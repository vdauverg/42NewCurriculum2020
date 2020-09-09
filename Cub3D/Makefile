# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:37:17 by vdauverg          #+#    #+#              #
#    Updated: 2020/09/09 13:09:54 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCDIR = ./src/
SRCS = Cub3D.c

LIBS = ./minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit ./Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	

$(NAME):
	@make -C Libft
	@make -sC minilibx_opengl_20191021
	gcc $(FLAGS) $(SRCDIR)$(SRCS) $(LIBS) -o $(NAME) -g

clean:
	@make clean -C Libft
	@make clean -C minilibx_opengl_20191021

fclean: clean
	@rm -f $(NAME)
	@make fclean -C Libft

re: fclean all
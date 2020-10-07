# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:10:49 by vdauverg          #+#    #+#              #
#    Updated: 2020/09/11 18:13:58 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SDIR = $(wildcard ./src/*)
ODIR = ./obj
IDIR = ./inc

_SRCS = *.c
_OBJS = *.o
_INCS = *.h

SRCS = $(foreach dir, $(SDIR), $(dir)/$(_SRCS))
OBJS = $(ODIR)/$(_OBJS)
INCS = $(IDIR)/$(_INCS)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(ODIR) $(SRCS)
	gcc $(FLAGS) -c $(SRCS) -I$(IDIR)
	mv $(_OBJS) $(ODIR)

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(ODIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

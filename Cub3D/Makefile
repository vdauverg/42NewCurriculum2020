# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:37:17 by vdauverg          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/10/07 14:06:25 by vincent          ###   ########.fr        #
=======
#    Updated: 2020/09/14 13:04:55 by vdauverg         ###   ########.fr        #
>>>>>>> 791103dec85d4d40e8450f0e3b71d92ecd3253a7
#                                                                              #
# **************************************************************************** #

NAME := Cub3D

SDIR := ./src
IDIR := ./inc
LDIR := ./lib
LDIRS := $(wildcard $(LDIR)/*)

_SRCS := $(patsubst $(SDIR)/%,%,$(wildcard $(SDIR)/*.c))
_INCS := $(patsubst $(IDIR)/%,%,$(wildcard $(IDIR)/*.h))
_LIBS = $(foreach lib,$(LDIRS),$(lib:%=%.a))

SRCS := $(patsubst %,$(SDIR)/%,$(_SRCS))
INCS := $(patsubst %,$(IDIR)/%,$(_INCS))
LIBS = $(foreach lib,$(LDIRS),$(lib:%=%/%.a))

IDIRS := $(IDIR) $(LDIR)/libft/inc

FLAGS := -Wall -Werror -Wextra
I = $(foreach i,$(IDIRS),-I$(i)) $(foreach lib,$(LDIRS),-L $(lib) -l$(lib:$(LDIR)/lib%=%))

all: $(NAME)
	
$(NAME): $(LIBS)
	gcc $(FLAGS) $(SRCS) $(I) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBS):
	@for lib in $(LDIRS); \
	do \
	echo "make -sC $$lib${\n}"; \
	make -sC $$lib; \
	done

clean:
	@for lib in $(LDIRS); \
	do \
	echo "make clean -sC $$lib${\n}"; \
	make clean -sC $$lib; \
	done

fclean: clean
	rm -f $(NAME)
	make fclean -sC $(LDIR)/libft

re: fclean all
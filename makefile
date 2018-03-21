# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klin <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 12:25:55 by klin              #+#    #+#              #
#    Updated: 2018/03/21 15:53:14 by klin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
FLAG = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

LIBFTDIR = ./libft

SRC = main.c \
	  exit.c \
	  init.c \
	  get_map.c \
	  ray.c \
	  draw.c \
	  key.c\
	  key_hook.c

OBJ = $(SRC:.c=.o)

HEAD = wolf.h
GCH = $(HEAD:.h=.h.gch)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(FLAG) -c $(SRC) $(HEAD)
	$(CC) -o $(NAME) $(OBJ) $(LIBFTDIR)/libft.a $(MLX)

clean :
	rm -f $(OBJ) $(GCH)
	make clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME) $(LIBFTDIR)/libft.a

re : fclean all

.PHONY: all clean fclean re

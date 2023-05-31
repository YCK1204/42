# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 18:41:29 by seongmpa          #+#    #+#              #
#    Updated: 2023/04/22 19:12:39 by yeckim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIB = libcub3d.a
LIBNAME = cub3d
CC = cc
CFLAGS1 = -Wall -Wextra -Werror -I ./mlx -I ./libft
CFLAGS = -Wall -Wextra -Werror -L./mlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
SRCS = ./src/check_arguments.c	\
		./src/check_map_util.c	\
		./src/check_map_util2.c	\
		./src/check_map.c		\
		./src/cub3d.c			\
		./src/dda_util.c		\
		./src/dda.c				\
		./src/gnl.c				\
		./src/key.c				\
		./src/key1.c			\
		./src/rgb.c				\
		./src/util.c			\
		./src/util1.c
INC = .
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS1) -I $(INC) -c -o $@ $^ 

$(LIB) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(NAME) : $(LIB)
	@make -C ./libft all
	@make -C ./mlx all
	@$(CC) $(CFLAGS) -L./libft -lft -l$(LIBNAME) -L. -o $@

clean:
	@make -C ./libft clean
	@make -C ./mlx clean
	@$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./mlx clean
	@$(RM) $(RMFLAGS) $(LIB) $(NAME) libmlx.a test

re: fclean all

.PHONY: all clean fclean re

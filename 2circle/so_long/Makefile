NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard ./mandatory/*.c)
OBJS_HEADER = mandatory_header/
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = $(wildcard ./bonus/*.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_HEADER_BONUS = bonus_header/
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

ifdef BONUS
	OBJ = $(OBJS_BONUS)
	HEAD = $(OBJS_HEADER_BONUS)
else
	OBJ = $(OBJS)
	HEAD = $(OBJS_HEADER)
endif

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -I $(HEAD) $(MLX_FLAGS) -o $@ $^
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

all : $(NAME)

bonus :
	make BONUS=1 all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: bonus re clean fclean all

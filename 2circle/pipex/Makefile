NAME = pipex
CC = cc
FALG = -Wall -Wextra -Werror -g#-fsanitize=address -g
SRCS = $(wildcard ./mandatory/*.c)
OBJS = $(SRCS:.c=.o)
#HEAD = $(wildcard ./mandatory_header/*.h)
SRCS_BONUS = $(wildcard ./bonus/*.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEAD_BONUS = $(wildcard ./bonus_header/*.h)

ifdef BONUS
	OBJ = $(OBJS_BONUS)
	HEADER = $(HEAD_BONUS)
else
	OBJ = $(OBJS)
	HEADER = $(HEAD)
endif

%.o : %.c
	$(CC) $(FALG) -c $^ -o $@

$(NAME) : $(OBJ)
	$(CC) $(FALG) -o $@ $^

all : $(NAME)

bonus :
	make BONUS=1 all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: bonus re all clean fclean

NAME = push_swap
CHECKER = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard ./mandatory/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = $(wildcard ./mandatory_header)
BONUS = $(wildcard ./bonus/*.c)
BONUS_OBJS = $(BONUS:.c=.o)
BONUS_INCLUDES = $(wildcard ./bonus_header)

%.o : %.c
	$(CC) $(FALGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -I $(INCLUDES) -o $@ $^

$(CHECKER) : $(BONUS_OBJS)
	$(CC) $(FLAGS) -I $(BONUS_INCLUDES) -o $@ $^

all : $(NAME)

bonus : all $(CHECKER)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(CHECKER)

re : fclean all

.PHONY: bonus re clean fclean all

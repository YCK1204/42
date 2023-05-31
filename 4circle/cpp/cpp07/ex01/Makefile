NAME = ex01
C++ = c++
FLAG = -Wall -Wextra -Werror -std=c++98
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(C++) $(FLAG) -c $^ -o $@

$(NAME) : $(OBJS)
	$(C++) $(FLAG) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: re all clean fclean

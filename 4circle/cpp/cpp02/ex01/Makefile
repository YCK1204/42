NAME = ex01
SRC = $(wildcard *.cpp)
HEAD = $(wildcard *.hpp)
OBJS = $(SRC:.cpp=.o)
C++ = c++
FLAG = -Wall -Werror -Wextra -std=c++98

%.o : %.cpp
	$(C++) $(FLAG) -c $^ -o $@
$(NAME) : $(OBJS)
	$(C++) $(FLAG) -I $(HEAD) -o $@ $^

all : $(NAME)

clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: re fclean clean all

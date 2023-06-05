NAME = convert
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
C++ = c++
FLAG = -Wall -Werror -Wextra -std=c++98

%.o : %.cpp
	$(C++) $(FLAG) -c $^ -o $@
$(NAME) : $(OBJS)
	$(C++) $(FLAG) -o $@ $^

all : $(NAME)

clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: re fclean clean all

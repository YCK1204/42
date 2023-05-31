BLACK       = "\033[0;30m"
GRAY        = "\033[1;30m"
RED         = "\033[0;31m"
GREEN       = "\033[0;32m"
YELLOW      = "\033[1;33m"
PURPLE      = "\033[0;35m"
CYAN        = "\033[0;36m"
WHITE       = "\033[1;37m"

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
NAME        = minishell
HEADER      = ./header/minishell.h
SRC			= $(wildcard ./src/*.c)
OBJ         = $(SRC:.c=.o)
LIBS		= -L ./src/libft -lft
RL_COM		= -I ${shell brew --prefix readline}/include
RL_LINK		= -L ${shell brew --prefix readline}/lib -lreadline

%.o : %.c
	@echo $(YELLOW) "Compiling...\t" $<
	@$(CC) $(CFLAGS) -I $(HEADER) ${RL_COM} -o $@ -c $<

$(NAME) : $(OBJ) $(HEADER)
	@echo $(GREEN) "Source files are compiled!\n\n"
	@echo $(YELLOW) "Building executable $(NAME)"
	@make all -C ./src/libft
	@$(CC) $(CFLAGS) $(LIBS) ${RL_LINK} -o $(NAME) $(OBJ)
	@echo $(GREEN) "$(NAME) is created!\n"

all : $(NAME)

clean :
	@echo $(YELLOW) "Cleaning object files..."
	@$(RM) $(OBJ)
	@make clean -C ./src/libft
	@echo $(RED) "Object files are cleaned!\n"

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..."
	@$(RM) $(NAME)
	@make fclean -C ./src/libft
	@echo $(RED) "$(NAME) is removed!\n\n"

re : fclean all
.PHONY : all clean fclean re

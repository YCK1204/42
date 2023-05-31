NAME = libftprintf.a
HEADER = ft_printf.h
CC = cc
FLAG = -Wall -Wextra -Werror
SRCS = ft_itoa.c	ft_operator.c	ft_option_percent_c.c	ft_option_percent_d.c \
	   ft_option_percent_low_x.c	ft_option_percent_up_x.c	ft_option_percent_p.c \
		ft_option_percent_u.c	ft_printf.c	ft_strlen.c	ft_option_percent_s.c





OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAG) -I $(HEADER) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $@ $^


all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: bonus re all clean fclean

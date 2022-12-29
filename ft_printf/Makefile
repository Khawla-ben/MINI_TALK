
NAME = libftprintf.a 
OBJECT = $(MY_FILES:.c=.o)

CC = cc -Wall -Wextra -Werror
AR = ar rc

MY_FILES = 	ft_printf.c \
			ft_check.c \
			ft_putchar.c \
			ft_printc.c \
			ft_prints.c \
			ft_printd.c \
			ft_printu.c \
			ft_printx.c 

all: $(NAME)

%.o: %.c 
	$(CC) -o $@ -c  $<

$(NAME): $(OBJECT) ft_printf.h
	$(AR) $@ $^

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all fclean clean re 

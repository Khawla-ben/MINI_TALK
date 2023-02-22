# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 06:22:18 by kben-ham          #+#    #+#              #
#    Updated: 2023/02/21 14:54:47 by kben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc

NAME = libftprintf.a 

AR = ar rc

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/libftprintf.a

MY_FILES = ft_atoi.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_check.c \
			ft_printf/ft_putchar.c \
			ft_printf/ft_printc.c \
			ft_printf/ft_prints.c \
			ft_printf/ft_printd.c \
			ft_printf/ft_printu.c \
			ft_printf/ft_printx.c 


OBJECT = $(MY_FILES:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client


all: $(NAME_CLIENT) $(NAME_SERVER) $(NAME)

%.o: %.c minitalk.h 
	$(CC)  $(CFLAGS) -o $@ -c  $<

$(NAME_CLIENT): $(OBJECT) client.o
	$(CC)  $(CFLAGS) $^ -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJECT) server.o
	$(CC)  $(CFLAGS) $^ -o $(NAME_SERVER)

$(NAME): $(OBJECT) ft_printf/ft_printf.h
	$(AR) $@ $^


	
NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

$(NAME_CLIENT_BONUS): $(OBJECT) client_bonus.o
	$(CC)  $(CFLAGS) $^ -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJECT) server_bonus.o
	$(CC)  $(CFLAGS) $^ -o $(NAME_SERVER_BONUS)
	
bonus: $(OBJECT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	rm -f $(OBJECT) 
	
fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS) libftprintf.a server.o client.o server_bonus.o client_bonus.o

re: fclean all

.PHONY : all fclean clean re 

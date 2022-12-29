# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 06:22:18 by kben-ham          #+#    #+#              #
#    Updated: 2022/12/28 16:17:32 by kben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/libftprintf.a

MY_FILES = ft_atoi.c


OBJECT = $(MY_FILES:.c=.o)


NAME_SERVER = server

NAME_CLIENT = client

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c minitalk.h
	$(CC)  $(CFLAGS) -o $@ -c  $<

$(NAME_CLIENT): $(OBJECT) client.o
	make all -C ft_printf
	$(CC)  $(CFLAGS) $^ $(FT_PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJECT) server.o
	$(CC)  $(CFLAGS) $^ $(FT_PRINTF) -o $(NAME_SERVER)

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

$(NAME_CLIENT_BONUS): $(OBJECT) client_bonus.o
	make all -C ft_printf
	$(CC)  $(CFLAGS) $^ $(FT_PRINTF) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJECT) server_bonus.o
	$(CC)  $(CFLAGS) $^ $(FT_PRINTF) -o $(NAME_SERVER_BONUS)
	
bonus: $(OBJECT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	make clean -C ft_printf
	rm -f $(OBJECT) 
	
fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS) ft_printf/libftprintf.a server.o client.o server_bonus.o client_bonus.o

re: fclean all

.PHONY : all fclean clean re 

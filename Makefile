# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:27:50 by cagutier          #+#    #+#              #
#    Updated: 2021/11/26 15:17:48 by cagutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

SRC_C = client.c\

SRC_S = server.c\

SRC_C_BONUS = client_bonus.c\

SRC_S_BONUS = server_bonus.c\

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(LIBFT) $(CLIENT)

$(CLIENT): $(LIBFT) $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@echo "\033[95mCliente compilado\033[0m"

$(SERVER): $(LIBFT) $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) -o $(SERVER)
	@echo "\033[95mServidor compilado\033[0m"

$(LIBFT): libft/*.c libft/*.h
	$(MAKE) -C Libft/

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:27:50 by cagutier          #+#    #+#              #
#    Updated: 2021/12/01 09:57:44 by cagutier         ###   ########.fr        #
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

all: $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@echo "\033[95mCliente compilado\033[0m"

$(SERVER): $(LIBFT) $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) -o $(SERVER)
	@echo "\033[95mServidor compilado\033[0m"

bonus: $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(LIBFT) $(SRC_C_BONUS)
	$(CC) $(CFLAGS) $(SRC_C_BONUS) $(LIBFT) -o $(CLIENT_BONUS)
	@echo "\033[95mCliente_bonus compilado\033[0m"

$(SERVER_BONUS): $(LIBFT) $(SRC_S_BONUS)
	$(CC) $(CFLAGS) $(SRC_S_BONUS) $(LIBFT) -o $(SERVER_BONUS)
	@echo "\033[95mServidor_bonus compilado\033[0m"

$(LIBFT): libft/*.c libft/*.h
	$(MAKE) -C Libft/

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus



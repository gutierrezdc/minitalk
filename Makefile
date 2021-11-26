# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:27:50 by cagutier          #+#    #+#              #
#    Updated: 2021/11/25 15:49:06 by cagutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS = server.c\
	   client.c\

SRCS_BONUS = server_bonus.c\
			 client_bonus.c\

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(SERVER)
	@echo "\033[95mServidor compilado\033[0m"

$(CLIENT): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(CLIENT)
	@echo "\033[95mCliente compilado\033[0m"




# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:27:50 by cagutier          #+#    #+#              #
#    Updated: 2021/11/26 10:55:05 by cagutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

CLIENT_BONUS = client_bonus

SRCS = client.c\

SRCS_BONUS = client_bonus.c\

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(LIBFT) $(CLIENT)

$(CLIENT): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(CLIENT)
	@echo "\033[95mCliente compilado\033[0m"

$(LIBFT): libft/*.c libft/*.h
	$(MAKE) -C Libft/

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	$(RM) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re



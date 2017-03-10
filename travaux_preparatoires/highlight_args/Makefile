# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/03/10 16:11:35 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= highlight
SRC= src/highlight.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
INC= inc
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft -j 8
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft -ltermcap

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC) $< -c -o $@
clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all

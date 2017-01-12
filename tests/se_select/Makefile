# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 16:27:25 by wbeets            #+#    #+#              #
#    Updated: 2014/01/09 14:51:29 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_select
FILES	= main.c\
		  listfunctions.c\
		  moves.c\
		  iskey.c\
		  iskey2.c\
		  set_get.c\
		  select_del_list.c\
		  listfunctions2.c\
		  print.c\
		  print2.c\
		  signal.c
SRC		= $(addprefix src/, $(FILES))
OBJ		= $(SRC:src/%.c=.obj/%.o)
FLAGS	= -Wall -Werror -Wextra
DFLAGS	= -Wall -Werror -Wextra -g3
LIBCOM	= -L libft -lft -L /usr/lib -ltermcap
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INCLUDE	= -I includes -I libft/includes
DEB		= .deb/test

all: $(NAME)

$(NAME): disp lib disp2 $(OBJ)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---"
	@gcc $(OBJ) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $@
	@echo  "$(OK_COLOR)\t---SUCCES---"
	@echo  "---COMPILATION COMPLETE---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-HOLD---COMPILING--- $(NO_COLOR)"

disp2:
	@echo  "\t---COMPILING---OBJECTS---"

.obj/%.o: src/%.c
	@mkdir -p .obj/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@make clean -C libft/

fclean:
	@rm -rf $(NAME)
	@rm -rf $(DEB)
	@make fclean -C libft/

re: fclean all

gdb:
	@mkdir -p .deb/
	@cc -o $(DEB) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRC)
	gdb $(DEB)

lib:
	@echo "\t---CHECKING LIBRARY---"
	@make -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

relib:
	@echo "\t---CHECKING LIBRARY---"
	@make re -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

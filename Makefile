# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 13:02:07 by seshevch          #+#    #+#              #
#    Updated: 2019/01/25 16:06:53 by seshevch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = seshevch.filler

LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = main.c fr_map1.c fr_map2.c

OBJ = main.o fr_map1.o fr_map2.o

INCL = ./libft/includes

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ): %.o: %.c
		gcc $(FLAGS) -c $< -o $@ -I $(INCL)

$(LIB):
		make -C ./libft

clean:
		rm -f $(OBJ)
		make clean -C ./libft

$(OBJ): %.o: %.c

fclean: clean
		rm -f $(NAME)
		make fclean -C ./libft

re: fclean all

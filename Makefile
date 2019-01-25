# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 13:02:07 by seshevch          #+#    #+#              #
#    Updated: 2019/01/25 12:32:06 by seshevch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = seshevch.filler

LIB = libfiller.a

PRF = libftprintf.a

SRCS = main.c get_next_line.c ft_strstr.c ft_strrchr.c ft_atoi.c fr_map1.c \
		fr_map2.c

OBJ = main.o get_next_line.o ft_strstr.o ft_strrchr.o ft_atoi.o fr_map1.o \
		fr_map2.o

all: $(NAME)

$(NAME): $(SRCS)
		@gcc -c $(SRCS) -I ./gnl/libft/includes
		@ar rc $(LIB) $(OBJ)
		@gcc -g $(PRF) $(SRCS)  -o $(NAME)


clean: $(OBJ)
		@rm -f $(OBJ) 

$(OBJ): %.c: %.o

fclean: clean
		@rm -rf $(LIB) $(NAME)

re: fclean all

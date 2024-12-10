# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:22:22 by abkhairi          #+#    #+#              #
#    Updated: 2024/10/14 13:48:19 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME   = easyfind

CC     = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC    = main.cpp
OBJ    = $(SRC:.cpp=.o)

 
%.o : %.cpp easyfind.hpp
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME) $(OBJ)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
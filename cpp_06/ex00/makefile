# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 16:13:35 by abkhairi          #+#    #+#              #
#    Updated: 2024/08/25 16:13:36 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Convert

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:	
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
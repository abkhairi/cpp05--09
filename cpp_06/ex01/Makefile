# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 16:13:15 by abkhairi          #+#    #+#              #
#    Updated: 2024/08/25 16:13:16 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Serializer

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = Serializer.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Serializer.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:	
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
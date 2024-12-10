# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:47:46 by abkhairi          #+#    #+#              #
#    Updated: 2024/10/14 13:49:19 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = Span

CC     = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC    = main.cpp Span.cpp
OBJ    = $(SRC:.cpp=.o)

 
%.o : %.cpp Span.hpp
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
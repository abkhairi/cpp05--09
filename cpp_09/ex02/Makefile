# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 11:31:25 by abkhairi          #+#    #+#              #
#    Updated: 2024/11/05 20:15:45 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME) $(OBJS) PmergeMe.hpp

%.o: %.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) PmergeMe.hpp
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
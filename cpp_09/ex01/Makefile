# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 14:31:44 by abkhairi          #+#    #+#              #
#    Updated: 2024/10/25 14:59:14 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = RPN

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp RPN.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
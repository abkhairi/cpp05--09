# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 16:14:00 by abkhairi          #+#    #+#              #
#    Updated: 2024/08/25 16:55:25 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Base

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Base.cpp A.cpp B.cpp C.cpp main.cpp func.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
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
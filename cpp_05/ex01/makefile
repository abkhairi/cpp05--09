NAME = exception

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all : $(NAME) $(OBJ)

$(NAME) : $(OBJ) Bureaucrat.hpp Form.hpp
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re all clean fclean
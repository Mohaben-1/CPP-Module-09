NAME = btc

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = BitcoinExchange.hpp

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

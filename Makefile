NAME	= ft_containers
CC		= c++
CFLAGS	= -Wall -Wextra -Werror
SRC		= test.cpp
OBJ		= $(SRC:.cpp=.o)
HEAD	= vector.hpp algorithm.hpp iterator_traits.hpp iterator.hpp \
		  map.hpp random_access_iterator.hpp reverse_iterator.hpp stack.hpp \
		  type_traits.hpp utility.hpp bidirectional_iterator.hpp

%.o : %.cpp $(HEAD)
	$(CC) $(CFLAGS) -c $(SRC)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
NAME	= ft_containers
CC		= c++
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft.cpp
OBJ		= $(SRC:.cpp=.o)
HEAD	= vector.hpp map.hpp stack.hpp _tree.hpp \
		  iterator.hpp random_access_iterator.hpp reverse_iterator.hpp tree_iterator.hpp \
		  functional.hpp type_traits.hpp utility.hpp algorithm.hpp

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
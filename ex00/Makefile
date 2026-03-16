NAME = Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

CPPS = Bureaucrat.cpp main.cpp

HPPS = Bureaucrat.hpp

OBJS = $(CPPS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HPPS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HPPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
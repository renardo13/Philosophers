
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = main.c \
init.c \
getter_setter.c \
utils.c \
utils_2.c \
meal.c \
ft_supervise.c \
ft_atoi.c \
error_type.c \

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
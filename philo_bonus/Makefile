
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRC = main.c \
init.c \
utils.c \
meal.c \
ft_supervise.c \
ft_atol.c \
ft_utils_2.c \
error_type.c \
ft_manage_threads.c \
ft_routine.c \

OBJ = $(SRC:.c=.o)

NAME = philo_bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
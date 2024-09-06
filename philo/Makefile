
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c \
init.c \
getter_setter.c \
utils.c \
libft_utils.c \
time_utils.c \
manage_threads.c \
supervise.c \
ft_atoi.c \
error_type.c \
routine.c \

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
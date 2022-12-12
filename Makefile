NAME = push_swap

SRC_A = main.c error_message.c ft_atoi.c arg.c current_status.c \
		sort_s.c sort_p.c

OBJ_A = $(SRC_A:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_A)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ_A)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

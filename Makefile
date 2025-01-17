NAME = push_swap

SRCS =	$(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
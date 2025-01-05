NAME = test

SRCS =	*.c
OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
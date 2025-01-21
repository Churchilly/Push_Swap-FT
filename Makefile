NAME = push_swap
NAME_BONUS = checker

SRCS =	atoi.c \
		error.c \
		free.c \
		ft_qsort.c \
		input.c \
		moves.c \
		moves_utils.c \
		operations.c \
		push_swap.c \
		solve.c \
		solve_counters.c \
		solve_functions.c \
		solve_double_functions.c \
		solve_function_utils.c \
		sort_small.c \
		sort_small_utils.c \
		sort_small_functions.c \
		split.c 

SRCS_BONUS =	checker_bonus.c \
				checker_atoi_bonus.c \
				checker_error_bonus.c \
				checker_free_bonus.c \
				checker_operations_bonus.c \
				checker_input_bonus.c \
				split.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS)
	cc -o $(NAME_BONUS) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re
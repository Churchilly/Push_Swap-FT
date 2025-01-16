#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <stdio.h>
#include <stdbool.h>

# define NULL_OP 0
# define PA 1
# define SA 2
# define RA 3
# define RRA 4
# define OP_DELIMETER 5
# define PB 6
# define SB 7
# define RB 8
# define RRB 9

typedef struct s_node
{
    int value;
    struct s_node *next;
}			t_node;

typedef struct s_stack
{
	t_node *top;
	int		size;
	char	name;
}			t_stack;

void	insert(int value, t_stack *stack);
int		swap(t_stack *stack, int op);
int		push(t_stack *stack_take, t_stack *stack_push, int op);
int		rotate(t_stack *stack, int op);
int		reverse_rotate(t_stack *stack, int op);

void	double_swap(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	double_reverse_rotate(t_stack *a, t_stack *b);

int		ft_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

void	input_error(char *message, t_stack *a);
void	process_error(char *message, t_stack *a, t_stack *b, t_node *moves);

void	insert_input(int argc, char **argv, t_stack *a);

void	solve(t_stack *a, t_stack *b, t_node *moves);
void	ft_qsort(int arr[], int low, int high);

void	sort_small(t_stack *a, t_stack *b, t_node *moves);
void	sort_small_a(t_stack *a, t_stack *b, t_node *moves);
void	sort_small_b(t_stack *a, t_stack *b, t_node *moves);

void	sort_2_a(t_stack *a, t_stack *b, t_node *moves);
void	sort_3_a(t_stack *a, t_stack *b, t_node *moves);
void	rev_sort_2_b(t_stack *a, t_stack *b, t_node *moves);
void	rev_sort_3_b(t_stack *a, t_stack *b, t_node *moves);

int		find_median(t_stack *stack);
int		divide_a(t_stack *a, t_stack *b, t_node *moves);
int		divide_b(t_stack *a, t_stack *b, t_node *moves);
void	assemble(t_stack *a, t_stack *b, int size, t_node *moves);

bool	is_sorted(t_stack *stack);
bool	is_rev_sorted(t_stack *stack);
void	free_moves(t_node *moves);
void	add_move(t_node *moves, int move, t_stack *a, t_stack *b);

void	print_moves(t_node *moves);
void	free_stacks(t_stack *a, t_stack *b);
void	free_moves(t_node *moves);

#endif
#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <stdio.h>
#include <stdbool.h>

# define NULL_OP 0
# define PA 1
# define SA 2
# define RA 3
# define RRA 4
# define OP_A 5
# define PB 6
# define SB 7
# define RB 8
# define RRB 9
# define OP_B 10
# define SS 11
# define RR 12
# define RRR 13

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

typedef struct s_moves
{
	t_node *a;
	t_node *b;
	int		total;
}			t_moves;


void	insert(int value, t_stack *stack);
void	swap(t_stack *stack, int op);
void	push(t_stack *stack_take, t_stack *stack_push, int op);
void	rotate(t_stack *stack, int op);
void	reverse_rotate(t_stack *stack, int op);

void	double_swap(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	double_reverse_rotate(t_stack *a, t_stack *b);

int		ft_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

void	input_error(char *message, t_stack *a);
void	process_error(char *message, t_stack *a, t_stack *b, t_moves *moves);

void	insert_input(int argc, char **argv, t_stack *a);

void	ft_qsort(int arr[], int low, int high);

void	sort_small(t_stack *a, t_stack *b, t_moves *moves);
void	sort_small_a(t_stack *a, t_stack *b, t_moves *moves);
void	sort_small_b(t_stack *a, t_stack *b, t_moves *moves);

void	sort_2_a(t_stack *a, t_stack *b, t_moves *moves);
void	sort_3_a(t_stack *a, t_stack *b, t_moves *moves);
void	rev_sort_2_b(t_stack *a, t_stack *b, t_moves *moves);
void	rev_sort_3_b(t_stack *a, t_stack *b, t_moves *moves);

int		find_median(t_stack *stack);
int		divide_a(t_stack *a, t_stack *b, t_moves *moves);
int		divide_b(t_stack *a, t_stack *b, t_moves *moves);
void	assemble(t_stack *a, t_stack *b, int size, t_moves *moves);

bool	is_sorted(t_stack *stack);
bool	is_rev_sorted(t_stack *stack);
void	solve(t_stack *a, t_stack *b);
void	free_moves(t_moves *moves);
void	add_move(t_moves *moves, int move, t_stack *a, t_stack *b);
void	pop_move(t_node **move_list);
void	make_move(t_stack *a, t_stack *b, t_moves *moves);

#endif
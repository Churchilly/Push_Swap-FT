#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <stdio.h>
#include <stdbool.h>

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

int		ft_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

int		input_error(char *message, t_stack *a);

void	insert_input(int argc, char **argv, t_stack *a);

void	ft_qsort(int arr[], int low, int high);

void	assemble(t_stack *a, t_stack *b, int size);
int		divide_a(t_stack *a, t_stack *b);
int		divide_b(t_stack *a, t_stack *b);
bool	is_sorted(t_stack *stack);
bool	is_rev_sorted(t_stack *stack);

void	sort_2_a(t_stack *a, t_stack *b);
void	sort_3_a(t_stack *a, t_stack *b);
void	rev_sort_2(t_stack *a, t_stack *b);
void	rev_sort_3(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_small_a(t_stack *a, t_stack *b);
void	sort_small_b(t_stack *a, t_stack *b);
void	solve(t_stack *a, t_stack *b);
int	find_median(t_stack *stack);
void	free_moves(t_moves *moves);

#endif
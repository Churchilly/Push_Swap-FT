#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <stdio.h>
#include <stdbool.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

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
void	swap(t_stack *stack);
void	push(t_stack *stack_take, t_stack *stack_push);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

int		ft_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

int		error(char *message, t_stack *a);

void	insert_input(int argc, char **argv, t_stack *a);

void	ft_qsort(int arr[], int low, int high);
void	sort_stacks(t_stack *a, t_stack *b);

void	assemble(t_stack *a, t_stack *b);
void	divide_half(t_stack *a, t_stack *b);
bool	is_sorted(t_stack *stack);

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	rev_sort_2(t_stack *stack);
void	rev_sort_3(t_stack *stack);
void	sort_small(t_stack *a, t_stack *b);
void	solve(t_stack *a, t_stack *b);
int	find_median(t_stack *stack);

#endif
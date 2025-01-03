#ifndef PUSH_SWAP
# define PUSH_SWAP


#include <stdio.h>


typedef struct s_node
{
    int value;
    struct s_node *next;
}			t_node;

typedef struct s_stack
{
	t_node *top;
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

#endif
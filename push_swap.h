/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:15:35 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/27 19:03:23 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

# define NULL_OP 0
# define PA 1
# define SA 2
# define RA 3
# define RRA 4
# define OP_SEP 5
# define PB 6
# define SB 7
# define RB 8
# define RRB 9

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	char	name;
	t_node	*top;
	int		size;
}			t_stack;

void	insert(int value, t_stack *stack);
int		swap(t_stack *stack, int op);
int		push(t_stack *stack_take, t_stack *stack_push, int op);
int		rotate(t_stack *stack, int op);
int		reverse_rotate(t_stack *stack, int op);

int		ft_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

void	input_error(char *message, t_stack *a);
void	process_error(char *message, t_stack *a, t_stack *b, t_node *moves);

void	insert_input(int argc, char **argv, t_stack *a);

void	ft_qsort(int arr[], int low, int high);
void	sort_small(t_stack *a, t_stack *b, t_node *moves);
void	sort_small_a(t_stack *a, t_stack *b, t_node *moves);
void	sort_small_b(t_stack *a, t_stack *b, t_node *moves);
void	sort_2_a(t_stack *a, t_stack *b, t_node *moves);
void	sort_3_a(t_stack *a, t_stack *b, t_node *moves);
void	rev_sort_2_b(t_stack *a, t_stack *b, t_node *moves);
void	rev_sort_3_b(t_stack *a, t_stack *b, t_node *moves);
int		divide_a(t_stack *a, t_stack *b, t_node *moves);
int		divide_b(t_stack *a, t_stack *b, t_node *moves);

int		get_min(t_node *head);
int		get_max(t_node *head);
int		position(t_node *head, int value);
int		place_a(t_stack *a, int value);
int		place_b(t_stack *b, int value);

int		count_double_r(t_stack *main, t_stack *side, int value);
int		count_double_rr(t_stack *main, t_stack *side, int value);
int		count_rarrb(t_stack *main, t_stack *side, int value);
int		count_rrarb(t_stack *main, t_stack *side, int value);
int		count_all(t_stack *main, t_stack *side);

int		double_r_a(t_stack *a, t_stack *b, t_node *moves, int value);
int		double_rr_a(t_stack *a, t_stack *b, t_node *moves, int value);
int		double_r_b(t_stack *a, t_stack *b, t_node *moves, int value);
int		double_rr_b(t_stack *a, t_stack *b, t_node *moves, int value);
int		rarrb_a(t_stack *a, t_stack *b, t_node *moves, int value);
int		rrarb_a(t_stack *a, t_stack *b, t_node *moves, int value);
int		rarrb_b(t_stack *a, t_stack *b, t_node *moves, int value);
int		rrarb_b(t_stack *a, t_stack *b, t_node *moves, int value);

bool	is_sorted(t_stack *stack);
bool	is_rev_sorted(t_stack *stack);

void	solve(t_stack *a, t_stack *b, t_node *moves);

void	add_move(t_node *moves, int move, t_stack *a, t_stack *b);
void	print_moves(t_node *moves);
void	free_stacks(t_stack *a, t_stack *b);
void	free_moves(t_node *moves);

#endif
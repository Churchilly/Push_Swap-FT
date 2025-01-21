/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:16 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 15:22:13 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_double_operation(int operation, t_node **a, t_node **b)
{
	if (operation == SA || operation == SB)
		write(1, "ss\n", 3);
	if (operation == RA || operation == RB)
		write(1, "rr\n", 3);
	if (operation == RRA || operation == RRB)
		write(1, "rrr\n", 4);
	(*a) = (*a)->next;
	(*b)->value = NULL_OP;
	(*b) = (*b)->next;
	while ((*b)->next && (*b)->value < 5)
		(*b) = (*b)->next;
}

static void	print_operation(int operation, t_node **a, t_node **b)
{
	if (operation == PA)
		write(1, "pa\n", 3);
	if (operation == SA)
		write(1, "sa\n", 3);
	if (operation == RA)
		write(1, "ra\n", 3);
	if (operation == RRA)
		write(1, "rra\n", 4);
	if (operation == PB)
		write(1, "pb\n", 3);
	if (operation == SB)
		write(1, "sb\n", 3);
	if (operation == RB)
		write(1, "rb\n", 3);
	if (operation == RRB)
		write(1, "rrb\n", 4);
	(*a) = (*a)->next;
	if ((*b)->next && (*a) == (*b))
		(*b) = (*b)->next;
}

void	print_moves(t_node *moves)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = moves->next;
	head_b = moves->next->next;
	while (head_a)
	{
		if ((head_a->value != PA || head_b->value != PA)
			&& (head_a->value == head_b->value - OP_SEP
				|| head_b->value == head_a->value - OP_SEP))
			print_double_operation(head_a->value, &head_a, &head_b);
		else
			print_operation(head_a->value, &head_a, &head_b);
	}
}

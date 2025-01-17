/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:16 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 03:05:51 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_double_operation(int operation, t_node **a, t_node **b)
{
	if (operation == SA)
		write(1, "SS\n", 3);
	if (operation == RA)
		write(1, "RR\n", 3);
	if (operation == RRA)
		write(1, "RRR\n", 4);
	(*a) = (*a)->next;
	(*b)->value = NULL_OP;
	(*b) = (*b)->next;
	while ((*b)->next && (*b)->value < 5)
		(*b) = (*b)->next;
}

static void	print_operation(int operation, t_node **a, t_node **b)
{
	if (operation == NULL_OP)
		return ;
	if (operation == PA)
		write(1, "PA\n", 3);
	if (operation == SA)
		write(1, "SA\n", 3);
	if (operation == RA)
		write(1, "RA\n", 3);
	if (operation == RRA)
		write(1, "RRA\n", 4);
	if (operation == PB)
		write(1, "PB\n", 3);
	if (operation == SB)
		write(1, "SB\n", 3);
	if (operation == RB)
		write(1, "RB\n", 3);
	if (operation == RRB)
		write(1, "RRB\n", 4);
	(*a) = (*a)->next;
	if ((*b)->next && (*a) == (*b))
		(*b) = (*b)->next;
}

void	print_moves(t_node *moves)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = moves->next;
	head_b = moves->next;
	while (head_a)
	{
		while (head_b->next && head_b->value < OP_SEP)
			head_b = head_b->next;
		if (head_a->value != PA && head_a->value == head_b->value - OP_SEP)
			print_double_operation(head_a->value, &head_a, &head_b);
		else
			print_operation(head_a->value, &head_a, &head_b);
	}
}

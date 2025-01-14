/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:16 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:38 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_moves(t_moves *moves)
{
	t_node	*tmp;
	t_node	*head;

	head = moves->a;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = moves->b;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	moves = NULL;
}
void	add_move(t_moves *moves, int move, t_stack *a, t_stack *b)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		solve_error("malloc error", a, b, moves);
	new->next = move;
	if (move < OP_A)
	{
		new->next = moves->a;
		moves->a = new;
		moves->total += 1;
	}
	else if (move < OP_B)
	{
		new->next = moves->b;
		moves->b = new;
		moves->total += 1;
	}
}

void	pop_move(t_node *move_list)
{
	t_node	*tmp;

	if (!move_list)
		return ;
	tmp = move_list;
	move_list = move_list->next;
	free(tmp);
}


static void	make_move_b(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->b)
	{	
		if (moves->b == SB)
			swap(b, SB);
		else if (moves->a == RB)
			rotate(b);
		else
			reverse_rotate(b, RRB);
		pop_move(moves->b);
	}
}

static void	make_move_a(t_stack *a, t_stack *b, t_moves *moves)
{
	if (moves->a == SA)
		swap(a, SA);
	else if (moves->a == RA)
		rotate(a, RA);
	else
		reverse_rotate(a, RRA);
	pop_move(moves->a);
	
}

void	make_move(t_stack *a, t_stack *b, t_moves *moves)
{
	// look stack a and b 
	// if moves->b - 5 == moves->a then do moves->b + 4
	if (!moves)
		return ;
	if (!(moves->a))
	{
		make_move_b(a, b, moves);
		return ;
	}
	if (moves->a == moves->b - 5)
	{
		if (moves->a == 2)
			ss();
		else if (moves->a == 3)
			rr();
		else
			rrr();
		pop_move(moves->a);
		pop_move(moves->b);
		moves->total -= 1;
	}
	make_move_a(a, b, moves);
	make_move(a, b, moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:16 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 18:44:14 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_move_b(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->b)
	{	
		if (moves->b->value == SB)
			swap(b, SB);
		else if (moves->a->value == RB)
			rotate(b, RB);
		else
			reverse_rotate(b, RRB);
		pop_move(&moves->b);
	}
}

static void	make_move_a(t_stack *a, t_stack *b, t_moves *moves)
{
	if (moves->a->value == SA)
		swap(a, SA);
	else if (moves->a->value == RA)
		rotate(a, RA);
	else
		reverse_rotate(a, RRA);
	pop_move(&moves->a);
}

void	make_move(t_stack *a, t_stack *b, t_moves *moves)
{
	// look stack a and b 
	// if moves->b - 5 == moves->a then do moves->b + 4

	// fuck it make moves only print dont make moves hereXD
	// need to change name to print moves :D
	
	if (!moves || (!(moves->a) && !(moves->b)))
		return ;
	if (!(moves->a) && moves->b)
	{
		make_move_b(a, b, moves);
		return ;
	}
	if (moves->a && moves->b && moves->a->value == (moves->b->value - 5))
	{
		if (moves->a->value == 2)
			double_swap(a, b);
		else if (moves->a->value == 3)
			double_rotate(a, b);
		else
			double_reverse_rotate(a, b);
		pop_move(&moves->a);
		pop_move(&moves->b);
		moves->total -= 1;
	}
	make_move_a(a, b, moves);
	make_move(a, b, moves);
}

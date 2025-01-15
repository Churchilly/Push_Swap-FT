/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:56 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 18:24:40 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_stack *a, t_stack *b, t_moves *moves)
{
	int	first;
	int	second;

	first = a->top->value;
	second = a->top->next->value;

	if (first > second)
		add_move(moves, SA, a, b);
}
void	sort_3_a(t_stack *a, t_stack *b, t_moves *moves)
{
	int first;
	int second;
	int third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (second > first && second > third && third > first) // 132
	{
		add_move(moves, SA, a, b);
		add_move(moves, RA, a, b);
	}
	else if (second > first && second > third && first > third) // 231
		add_move(moves, RRA, a, b);
	else if (first > second && first > third && third > second) // 312
		add_move(moves, RA, a, b);
	else if (first > second && first > third && second > third) // 321
	{
		add_move(moves, RA, a, b);
		add_move(moves, SA, a, b);
	}
	else if (third > first && third > second && first > second) // 213
		add_move(moves, SA, a, b);
}

void	rev_sort_2_b(t_stack *a, t_stack *b, t_moves *moves)
{
	int first;
	int second;

	first = b->top->value;
	second = b->top->next->value;
	if (first < second)
		add_move(moves, SB, a, b);
}

void	rev_sort_3_b(t_stack *a, t_stack *b, t_moves *moves)
{
	int	first;
	int	second;
	int	third;
	
	first = b->top->value;
	second = b->top->next->value;
	third = b->top->next->next->value;
	if (first > second && first > third && third > second) // 312
	{
		add_move(moves, RRB, a, b);
		add_move(moves, SB, a, b);
	}
	if (second > first && second > third && third > first) // 132
		add_move(moves, RB, a, b);

	if (second > first && second > third && first > third) // 231
		add_move(moves, SB, a, b);
	if (third > first && third > second && second > first) // 123
	{
		add_move(moves, SB, a, b);
		add_move(moves, RRB, a, b);
	}
	if (third > first && third > second && first > second) // 213
		add_move(moves, RRB, a, b);
}
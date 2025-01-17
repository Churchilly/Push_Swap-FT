/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:56 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 03:15:10 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_stack *a, t_stack *b, t_node *moves)
{
	int	first;
	int	second;

	first = a->top->value;
	second = a->top->next->value;
	if (first > second)
		add_move(moves, swap(a, SA), a, b);
}

void	sort_3_a(t_stack *a, t_stack *b, t_node *moves)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (second > first && second > third && third > first)
	{
		add_move(moves, swap(a, SA), a, b);
		add_move(moves, rotate(a, RA), a, b);
	}
	else if (second > first && second > third && first > third)
		add_move(moves, reverse_rotate(a, RRA), a, b);
	else if (first > second && first > third && third > second)
		add_move(moves, rotate(a, RA), a, b);
	else if (first > second && first > third && second > third)
	{
		add_move(moves, rotate(a, RA), a, b);
		add_move(moves, swap(a, SA), a, b);
	}
	else if (third > first && third > second && first > second)
		add_move(moves, swap(a, SA), a, b);
}

void	rev_sort_2_b(t_stack *a, t_stack *b, t_node *moves)
{
	int	first;
	int	second;

	first = b->top->value;
	second = b->top->next->value;
	if (first < second)
		add_move(moves, swap(b, SB), a, b);
}

void	rev_sort_3_b(t_stack *a, t_stack *b, t_node *moves)
{
	int	first;
	int	second;
	int	third;

	first = b->top->value;
	second = b->top->next->value;
	third = b->top->next->next->value;
	if (first > second && first > third && third > second)
	{
		add_move(moves, reverse_rotate(b, RRB), a, b);
		add_move(moves, swap(b, SB), a, b);
	}
	if (second > first && second > third && third > first)
		add_move(moves, rotate(b, RB), a, b);
	if (second > first && second > third && first > third)
		add_move(moves, swap(b, SB), a, b);
	if (third > first && third > second && second > first)
	{
		add_move(moves, swap(b, SB), a, b);
		add_move(moves, reverse_rotate(b, RRB), a, b);
	}
	if (third > first && third > second && first > second)
		add_move(moves, reverse_rotate(b, RRB), a, b);
}

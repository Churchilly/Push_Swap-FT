/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 03:17:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int get_min(t_node *head)
{
	int 	min;

	min = head->value;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
		}
		head = head->next;
	}
	return (min);
}

int get_max(t_node *head)
{
    int 	max;

    max = head->value;
    while (head)
    {
        if (head->value > max)
        {
            max = head->value;
        }
        head = head->next;
    }
    return (max);
}

static void	merge(t_stack *a, t_stack *b, t_node *moves)
{
	int		double_moves;
	int		count;
	t_node	*head;
	while (b->size)
	{
		head = b->top;
		double_moves = count_all(b, a);
		while (double_moves != -1)
		{
			if (double_moves == count_double_r(b, a, head->value))
				double_moves = double_rotate_b(a, b, moves, head->value);
			else if (double_moves == count_double_rr(b, a, head->value))
				double_moves = double_reverse_rotate_b(a, b, moves, head->value);
			else if (double_moves == count_rarrb(b, a, head->value))
				double_moves = rarrb_b(a, b, moves, head->value);
			else if (double_moves == count_rrarb(b, a, head->value))
				double_moves =rrarb_b(a, b, moves, head->value);
			else
				head = head->next;
		}
	}
}

static void	partition(t_stack *a, t_stack *b, t_node *moves)
{
	int		double_moves;
	t_node	*head;

	while (a->size > 5 && !is_sorted(a))
	{
		head = a->top;
		double_moves = count_all(a, b);
		while (double_moves != -1)
		{
			if (double_moves == count_double_r(a, b, head->value))
				double_moves = double_rotate_a(a, b, moves, head->value);
			else if (double_moves == count_double_rr(a, b, head->value))
				double_moves = double_reverse_rotate_a(a, b, moves, head->value);
			else if (double_moves == count_rarrb(a, b, head->value))
				double_moves = rarrb_a(a, b, moves, head->value);
			else if (double_moves == count_rrarb(a, b, head->value))
				double_moves = rrarb_a(a, b, moves, head->value);
			else
				head = head->next;
		}
	}
}

void	solve(t_stack *a, t_stack *b, t_node *moves)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size <= 10)
		return (sort_small(a, b, moves));
	add_move(moves, push(a, b, PB), a, b);
	if (!is_sorted(a))
		add_move(moves, push(a, b, PB), a, b);
	partition(a, b, moves);
	sort_small_a(a, b, moves);
	merge(a, b, moves);
	if (position(a->top, get_min(a->top)) < a->size)
	{
		while (a->top->value != get_min(a->top))
			add_move(moves, rotate(a, RA), a, b);
	}
	else
	{
		while (a->top->value != get_min(a->top))
			add_move(moves, reverse_rotate(a, RRA), a, b);		
	}
}

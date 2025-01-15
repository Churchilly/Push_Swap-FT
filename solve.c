/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 18:38:55 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sort_stack_a(t_stack *a, t_stack *b, t_moves *moves);

static void	partition_b(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;
	int	size;
	int	pivot;
	
	i = 0;
	size = a->size;
	pivot = find_median(a);
	while (i < size)
	{
		if (a->top->value >= pivot)
			add_move(moves, PB, a, b);
		else
			add_move(moves, RA, a, b);
		i++;
	}
}

static void	sort_stack_b(t_stack *a, t_stack *b, t_moves *moves)
{
	if (is_rev_sorted(b))
		return ;
	if (b->size <= 5)
	{
		sort_small_b(a, b, moves);
		return ;
	}
	partition_b(a, b, moves);
	sort_stack_a(a, b, moves);
	sort_stack_b(a, b, moves);
}

static void	partition_a(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;
	int	size;
	int	pivot;
	
	i = 0;
	size = a->size;
	pivot = find_median(a);
	while (i < size)
	{
		if (a->top->value < pivot)
			add_move(moves, PB, a, b);
		else
			add_move(moves, RA, a, b);
		i++;
	}
}

static void	sort_stack_a(t_stack *a, t_stack *b, t_moves *moves)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small_a(a, b, moves);
		return ;
	}
	partition_a(a, b, moves);
	sort_stack_a(a, b, moves);
	sort_stack_b(a, b, moves);
}

void	solve(t_stack *a, t_stack *b)
{
	t_moves	moves;
	
	moves.a = NULL;
	moves.b = NULL;
	moves.total = 0;
	if (a->size == 1)
		return ;
	if (a->size <= 10 || is_sorted(a))
	{
		sort_small(a, b, &moves);
		make_move(a, b, &moves);
		return ;
	}
	sort_stack_a(a, b, &moves);
	make_move(a, b, &moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 22:38:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_stack_b(t_stack *a, t_stack *b, t_moves *moves)
{
	if (is_rev_sorted(b))
		return ;
	if (b->size <= 5)
	{
		sort_small_b(a, b);
		return ;
	}
	partition_b(a, b, moves);
	sort_stack_a(a, b, moves);
	sort_stack_b(a, b, moves);
}

void	partition_a(t_stack *a, t_stack *b, t_moves *moves)
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
			push(a, b);
		else
			rotate(a);
		i++;
	}
}

void	sort_stack_a(t_stack *a, t_stack *b, t_moves *moves)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small_a(a, b);
		return ;
	}
	partition_a(a, b, moves);
	sort_stack_a(a, b, moves);
	sort_stack_b(a, b, moves);
}

void	solve(t_stack *a, t_stack *b)
{
	t_moves	moves;
	
	if (a->size == 1)
		return ;
	if (a->size <= 10 || is_sorted(a))
	{
		sort_small(a, b);
		return ;
	}
	sort_stack_a(a, b, &moves);
	make_moves(a, b, moves);
	free_moves(&moves);
}

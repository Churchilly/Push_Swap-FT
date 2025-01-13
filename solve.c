/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/13 16:12:28 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition(t_stack *a, t_stack *b, int pivot)
{
	int i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->top->value < pivot)
			push(a, b);
		else
			rotate(a);
		i++;
	}
}


void	sort_stacks(t_stack *a, t_stack *b)
{
	int	pivot;
	
	if (a->size <= 5)
	{
		sort_small_a(a, b);
		return ;
	}
	pivot = find_median(a);
	partition(a, b, pivot);
	sort_small_a(a, b);
	while (b->size > 0)
		push(b, a);
}

void	solve(t_stack *a, t_stack *b)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size <= 10)
	{
		sort_small(a, b);
		return ;
	}
	sort_stacks(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/09 18:07:50 by yusudemi         ###   ########.fr       */
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
		sort_small(a, b);
		return ;
	}
	pivot = find_median(a);
	printf("size: %d median:%d\n",a->size, pivot);
	partition(a, b, pivot);
	sort_stacks(a, b);
	while (b->size > 0)
		push(b, a);
}

void	solve(t_stack *a, t_stack *b)
{
	if (!is_sorted(a) && a->size <= 6)
		sort_small(a, b);
	sort_stacks(a, b);
	//while (!is_sorted(a))
	//{
	//}
}

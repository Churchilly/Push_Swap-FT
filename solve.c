/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/06 11:43:04 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_median(t_stack *stack)
{
	int		buffer[stack->size];
	t_node	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	while (i < stack->size)
	{
		buffer[i] = curr->value;
		curr = curr->next;
		i++;
	}
	ft_qsort(buffer, 0, stack->size - 1);
	printf("{%d}\n",buffer[stack->size / 2]);
	return (buffer[stack->size / 2]);
}

static void	partition(t_stack *a, t_stack *b, int pivot)
{
	int i;

	i = 0;
	while (i < a->size)
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
	
	if (a->size <= 1)
		return;
	pivot = find_median(a);
	printf("size: %d median:%d\n",a->size, pivot);
	partition(a, b, pivot);
	while (b->size > 0)
		push(b, a);
}

void	solve(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		//	add sort for small array
		//	add sort_stacks for big arrays
		//	maybe need to think
		/*	after sorting the first half you cannot
			use rotate as u use it on partitioning
			section need to think something else */
		// for a remainder dont forget to add print operation function
	}
}

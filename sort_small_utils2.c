/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:02:32 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 18:05:07 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

static int	find_median_small(t_stack *stack)
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
	if (stack->size <= 6)
		return (buffer[stack->size / 2]);
	return (buffer[stack->size - 5]);
}

int	divide_a(t_stack *a, t_stack *b)
{
	t_node	*head;
	int		median;
	int		size;
	int		ret;
	
	ret = 0;	
	if (a->size <= 3)
		return (0);
	median = find_median_small(a);
	size = a->size;
	while (size--)
	{
		head = a->top;
		if (head->value < median)
		{
			ret++;
			push(a, b);
		}
		else
			rotate(a);
	}
	return (ret);
}

int	divide_b(t_stack *a, t_stack *b)
{
	t_node	*head;
	int		median;
	int		size;
	int		ret;
	
	ret = 0;	
	if (b->size <= 3)
		return (0);
	median = find_median_small(b);
	size = b->size;
	while (size--)
	{
		head = b->top;
		if (head->value > median)
		{
			ret++;
			push(b, a);
		}
		else
			rotate(b);
	}
	return (ret);
}

void	assemble(t_stack *a, t_stack *b, int size)
{
	while (size--)
	{
		push(b, a);
	} 
}



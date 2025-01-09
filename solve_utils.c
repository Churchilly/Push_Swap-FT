/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:02:32 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/09 17:36:09 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*head;

	head = stack->top;
	while (head->next)
	{
		if (head > head->next)
			return (false);
		head = head->next;
	}
	return (true);
}

void	divide_half(t_stack *a, t_stack *b)
{
	t_node	*head;
	int	median;
	int	size;
	
	median = find_median(a);
	printf("med:%d\n", median);
	size = a->size;
	while (size--)
	{
		head = a->top;
		if (head->value < median)
			push(a, b);
		else
			rotate(a);
	}
}

void	assemble(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		push(b, a);
	} 
}

int	find_median(t_stack *stack)
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
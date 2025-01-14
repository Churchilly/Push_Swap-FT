/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:51:42 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 22:10:40 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (buffer[stack->size / 2]);
}

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

bool	is_rev_sorted(t_stack *stack)
{
	t_node	*head;

	head = stack->top;
	while (head->next)
	{
		if (head < head->next)
			return (false);
		head = head->next;
	}
	return (true);
}
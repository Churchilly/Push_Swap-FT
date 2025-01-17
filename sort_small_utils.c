/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:02:32 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/18 00:19:50 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

static int	find_median_small(t_stack *stack, t_stack *s_free, t_node *moves)
{
	int		*buffer;
	t_node	*curr;
	int		i;
	int		ret;

	buffer = malloc(sizeof(int) * stack->size);
	if (!buffer)
		process_error("Malloc error.", stack, s_free, moves);
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
		ret = (buffer[stack->size / 2]);
	else
		ret = (buffer[stack->size - 5]);
	free(buffer);
	return (ret);
}

int	divide_a(t_stack *a, t_stack *b, t_node *moves)
{
	t_node	*head;
	int		median;
	int		size;
	int		ret;

	ret = 0;
	if (a->size <= 3)
		return (0);
	median = find_median_small(a, b, moves);
	size = a->size;
	while (size--)
	{
		head = a->top;
		if (head->value < median)
		{
			ret++;
			add_move(moves, push(a, b, PB), a, b);
		}
		else
			add_move(moves, rotate(a, RA), a, b);
	}
	return (ret);
}

int	divide_b(t_stack *a, t_stack *b, t_node *moves)
{
	t_node	*head;
	int		median;
	int		size;
	int		ret;

	ret = 0;
	if (b->size <= 3)
		return (0);
	median = find_median_small(b, a, moves);
	size = b->size;
	while (size--)
	{
		head = b->top;
		if (head->value > median)
		{
			ret++;
			add_move(moves, push(b, a, PA), a, b);
		}
		else
			add_move(moves, rotate(b, RB), a, b);
	}
	return (ret);
}

bool	is_sorted(t_stack *stack)
{
	t_node	*head;

	head = stack->top;
	while (head->next)
	{
		if (head->value > head->next->value)
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
		if (head->value < head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

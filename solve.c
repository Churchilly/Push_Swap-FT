/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/18 04:51:54 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	fill_position_buffer(t_stack *stack, int *buffer)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = -1;
	while (++i < stack->size)
	{
		buffer[i] = current->value;
		current = current->next;
	}
	ft_qsort(buffer, 0, stack->size - 1);
}

int	get_index(t_stack *a, int pivot)
{
	int		i;
	t_node	*head;

	i = 0;
	head = a->top;
	while (i < a->size)
	{
		if (head->value <= pivot)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

void	get_pivot(t_stack *a, t_stack *b, t_node *moves, int idx)
{
	while (idx > 0 && idx < a->size)
	{
		if (idx <= (a->size / 2))
		{
			add_move(moves, rotate(a, RA), a, b);
			idx--;
		}
		else
		{
			add_move(moves, reverse_rotate(a, RRA), a, b);
			idx++;
		}
	}
}

int get_min_idx(t_stack *stack)
{
	int 	ret;
	int		i;
	int 	min;
	t_node *head;

	head = stack->top;
	min = head->value;
	i = 0;
	ret = 0;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			ret = i;
		}
		i++;
		head = head->next;
	}
	return (ret);
}

int get_max_idx(t_stack *stack)
{
	int 	ret;
	int		i;
	int 	max;
	t_node *head;

	head = stack->top;
	max = head->value;
	i = 0;
	ret = 0;
	while (head)
	{
		if (head->value > max)
		{
			max = head->value;
			ret = i;
		}
		i++;
		head = head->next;
	}
	return (ret);
}

void	get_biggest_b(t_stack *a, t_stack *b, t_node *moves)
{
	int max_b;
	
	max_b = get_max_idx(b);
	while (max_b > 0 && max_b < b->size)
	{
		if (max_b <= (b->size / 2))
		{
			add_move(moves, rotate(b, RB), a, b);
			max_b--;
		}
		else
		{
			add_move(moves, reverse_rotate(b, RRB), a, b);
			max_b++;
		}
	}
}

static void	sort_stacks(t_stack *a, t_stack *b, t_node *moves, int *buffer)
{
	int	i;
	int idx;

	if (is_sorted(a))
		return ;
	if (a->size < 5)
		return (sort_small_a(a, b, moves));
	buffer = malloc(sizeof(int) * a->size);
	if (!buffer)
		process_error("Malloc error.", a, b, moves);
	fill_position_buffer(a, buffer);
	i = 0;
	while (++i < 6)
	{
		idx = get_index(a, buffer[(a->size * i) / 4]);
		while (idx != -1)
		{
			get_pivot(a, b, moves, idx);
			add_move(moves, push(a, b, PB), a, b);
			idx = get_index(a, buffer[(a->size * i) / 4]);
		}
	}
	free(buffer);
	sort_stacks(a, b, moves, buffer);
	while (b->size > 0)
	{
		get_biggest_b(a, b, moves);
		add_move(moves, push(b, a, PA), a, b);
	}
}

void	sort_big_stacks(t_stack *a, t_stack *b, t_node *moves, int *buffer)
{
	int i;
	int idx;
	
	buffer = malloc(sizeof(int) * a->size);
	if (!buffer)
		process_error("Malloc error.", a, b, moves);
	fill_position_buffer(a, buffer);
	i = 0;
	while (++i < 8)
	{
		idx = get_index(a, buffer[(a->size * i) / 8]);
		while (idx != -1)
		{
			get_pivot(a, b, moves, idx);
			add_move(moves, push(a, b, PB), a, b);
			idx = get_index(a, buffer[(a->size * i) / 8]);
		}
	}
	free(buffer);
	sort_stacks(a, b, moves, buffer);
}

void	solve(t_stack *a, t_stack *b, t_node *moves)
{
	int	*buffer;

	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size <= 10)
		return (sort_small(a, b, moves));
	if (a->size <= 100)
		sort_stacks(a, b, moves, buffer);
	else
		sort_big_stacks(a, b, moves, buffer);
	//free(buffer);
}

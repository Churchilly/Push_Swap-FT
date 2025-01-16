/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:37:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 01:06:05 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	position(t_stack *stack, int *buffer)
{
	int	pos;

	pos = 0;
	while (buffer[pos] != stack->top->value)
		pos++;
	return (pos);	
}

static void	get_bits(int *max_bits, int size)
{
	(*max_bits) = 0;
	while (size >> *(max_bits))
		(*max_bits)++;
}

static void	sort_stacks(t_stack *a, t_stack *b, t_node *moves)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	int buffer[a->size];
	
	fill_position_buffer(a, buffer);
	get_bits(&max_bits, a->size);
	size = a->size;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((position(a, buffer) >> i) & 1)
				add_move(moves, rotate(a, RA), a, b);
			else
				add_move(moves, push(a, b, PB), a, b);
		}
		while (b->size)
			add_move(moves, push(b, a, PA), a, b);
	}
}

void	solve(t_stack *a, t_stack *b, t_node *moves)
{	
	if (a->size == 1)
		return ;
	if (a->size <= 10 || is_sorted(a))
		return (sort_small(a, b, moves));
	sort_stacks(a, b, moves);
}

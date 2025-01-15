/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:37:11 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 17:45:25 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	insert(int value, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		input_error("malloc error", stack);
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size = stack->size + 1;
}

void	swap(t_stack *stack, int op)
{
	t_node	*first;
	t_node	*second;
	
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *stack_take, t_stack *stack_push, int op)
{
	t_node	*taken;
	
	if (op == PA)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	if (!stack_take->top)
		return ;
	taken = stack_take->top;
	stack_take->top = stack_take->top->next;
	taken->next = stack_push->top;
	stack_push->top = taken;
	stack_take->size = stack_take->size - 1;
	stack_push->size = stack_push->size + 1;
	
}

void	rotate(t_stack *stack, int op)
{
	t_node	*first;
	t_node	*last;
	
	if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RR)
		write(1, "rr\n", 3);
	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack, int op)
{
	t_node	*prev;
	t_node	*curr;
	
	if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else if (op == RRR)
		write(1, "rrr\n", 4);
	if (!stack->top || !stack->top->next)
		return ;
	prev = NULL;
	curr = stack->top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = stack->top;
	stack->top = curr;
	prev->next = NULL;
}

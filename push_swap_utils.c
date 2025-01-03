/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:37:11 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/03 06:46:50 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

void	insert(int value, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		error("malloc error", stack);
	new->value = value;
	new->next = stack->top;
	stack->top = new;
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	
	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *stack_take, t_stack *stack_push)
{
	t_node	*taken;
	
	if (!stack_take->top)
		return ;
	taken = stack_take->top;
	stack_take->top = stack_take->top->next;
	taken->next = stack_push->top;
	stack_push->top = taken;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	
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

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*curr;
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
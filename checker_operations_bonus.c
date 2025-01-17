/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:57:18 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/18 00:04:11 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stddef.h>

static void	swap(t_stack *stack)
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

static void	push(t_stack *stack_take, t_stack *stack_push)
{
	t_node	*taken;

	if (!stack_take->top)
		return ;
	taken = stack_take->top;
	stack_take->top = stack_take->top->next;
	taken->next = stack_push->top;
	stack_push->top = taken;
	stack_take->size = stack_take->size - 1;
	stack_push->size = stack_push->size + 1;
	return ;
}

static void	rotate(t_stack *stack)
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

static void	reverse_rotate(t_stack *stack)
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

void	make_operation(t_stack *a, t_stack *b, int operation)
{
	if (operation == PA)
		return (push(b, a));
	if (operation == SA)
		return (swap(a));
	if (operation == RA)
		return (rotate(a));
	if (operation == RRA)
		return (reverse_rotate(a));
	if (operation == PB)
		return (push(a, b));
	if (operation == SB)
		return (swap(b));
	if (operation == RB)
		return (rotate(b));
	if (operation == RRB)
		return (reverse_rotate(b));
	if (operation == SS)
		return (swap(a), swap(b));
	if (operation == RR)
		return (rotate(a), rotate(b));
	if (operation == RRR)
		return (reverse_rotate(a), reverse_rotate(b));
}

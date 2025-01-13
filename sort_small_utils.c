/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:56 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/13 15:56:05 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->top->value;
	second = stack->top->next->value;

	if (first > second)
		swap(stack);
}
void	sort_3(t_stack *stack)
{
	int first;
	int second;
	int third;

	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (second > first && second > third && third > first) // 132
	{
		swap(stack); // -> 312
		rotate(stack); // -> 123
	}
	else if (second > first && second > third && first > third) // 231
		reverse_rotate(stack); // -> 123
	else if (first > second && first > third && third > second) // 312
		rotate(stack); // -> 123
	else if (first > second && first > third && second > third) // 321
	{
		rotate(stack); // -> 213
		swap(stack); // -> 123
	}
	else if (third > first && third > second && first > second) // 213
		swap(stack); // -> 123
}

void	rev_sort_2(t_stack *stack)
{
	int first;
	int second;

	first = stack->top->value;
	second = stack->top->next->value;
	if (first < second)
		swap(stack);
}

void	rev_sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;
	
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && first > third && third > second) // 312
	{
		reverse_rotate(stack); // -> 231
		swap(stack);
	}
	if (second > first && second > third && third > first) // 132
		rotate(stack); // -> 321
	if (second > first && second > third && first > third) // 231
		swap(stack); // ->321
	if (third > first && third > second && second > first) // 123
	{
		swap(stack); // -> 213
		reverse_rotate(stack); // -> 321
	}
	if (third > first && third > second && first > second) // 213
		reverse_rotate(stack); // -> 321
}
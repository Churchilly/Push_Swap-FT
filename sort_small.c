/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:39:25 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/09 18:11:19 by yusudemi         ###   ########.fr       */
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
	if (second > first && second > third && third > first) // 132 && 231
	{
		swap(stack); // -> 312
		rotate(stack); // -> 123
	}
	else if (second > first && second > third && first > third) // 231
		reverse_rotate(stack); // -> 123
	else if (first > second && first > third && third > second) // 312
		rotate(stack); // -> 123
	else if (first > second && first > third && second > third)
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
	printf("f:%ds:%d\n", first, second);
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
		reverse_rotate(stack); // -> 231
	if (second > first && second > third) // 132 && 231
	{
		if (third > first) // 132
			reverse_rotate(stack); // -> 321
		else // 231
			swap(stack); // -> 321
	}
	if (third > first && third > second && first > second) // 213
		reverse_rotate(stack); // -> 321
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size > 3)
	{
		divide_half(a, b);
		if (a->size == 2)
		{
			sort_2(a);
			rev_sort_2(b);
		}
		else if (a->size == 3 && b->size == 3)
		{
			sort_3(a);
			rev_sort_3(b);
		}
		else if (a->size == 3)
		{
			sort_3(a);
			rev_sort_2(b);
		}
		assemble(a, b);
	}
}

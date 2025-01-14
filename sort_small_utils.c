/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:56 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:35 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	first = a->top->value;
	second = a->top->next->value;

	if (first > second)
		swap(a);
}
void	sort_3_a(t_stack *a, t_stack *b)
{
	int first;
	int second;
	int third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (second > first && second > third && third > first) // 132
	{
		swap(a); // -> 312
		rotate(a); // -> 123
	}
	else if (second > first && second > third && first > third) // 231
		reverse_rotate(a); // -> 123
	else if (first > second && first > third && third > second) // 312
		rotate(a); // -> 123
	else if (first > second && first > third && second > third) // 321
	{
		rotate(a); // -> 213
		swap(a); // -> 123
	}
	else if (third > first && third > second && first > second) // 213
		swap(a); // -> 123
}

void	rev_sort_2_b(t_stack *a, t_stack *b)
{
	int first;
	int second;

	first = b->top->value;
	second = b->top->next->value;
	if (first < second)
		swap(b);
}

void	rev_sort_3_b(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;
	
	first = b->top->value;
	second = b->top->next->value;
	third = b->top->next->next->value;
	if (first > second && first > third && third > second) // 312
	{
		reverse_rotate(b); // -> 231
		swap(b);
	}
	if (second > first && second > third && third > first) // 132
		rotate(b); // -> 321
	if (second > first && second > third && first > third) // 231
		swap(b); // ->321
	if (third > first && third > second && second > first) // 123
	{
		swap(b); // -> 213
		reverse_rotate(b); // -> 321
	}
	if (third > first && third > second && first > second) // 213
		reverse_rotate(b); // -> 321
}
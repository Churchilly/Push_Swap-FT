/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:39:25 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/13 16:12:07 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_a(t_stack *a, t_stack *b)
{
	int	ret;

	ret = divide_half_a(a, b);
	printf("%d\n", ret);
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	if (ret == 2)
		rev_sort_2(b);
	else if (ret == 3)
		rev_sort_3(b);
	if (ret)
		assemble(a, b, ret);
}

void	sort_small_b(t_stack *a, t_stack *b)
{
	int	ret;

	ret = divide_half_b(a, b);
	if (b->size == 2)
		rev_sort_2(b);
	if (b->size == 3)
		rev_sort_3(b);
	if (ret == 2)
		sort_2(a);
	while (b->size)
		push(b, a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	ret;
	
	if (a->size <= 6)
	{
		sort_small_a(a, b);
		return ;
	}
	ret = divide_half_a(a, b);
	sort_small_a(a, b);
	sort_small_b(a, b);
}

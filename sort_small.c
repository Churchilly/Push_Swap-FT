/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:39:25 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/14 18:43:13 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_a(t_stack *a, t_stack *b)
{
	int	ret;

	ret = divide_a(a, b);
	printf("%d\n", ret);
	if (a->size == 2)
		sort_2_a(a, b);
	else if (a->size == 3)
		sort_3_a(a, b);
	if (ret == 2)
		rev_sort_2(a, b);
	else if (ret == 3)
		rev_sort_3(a, b);
	if (ret)
		assemble(a, b, ret);
}

void	sort_small_b(t_stack *a, t_stack *b)
{
	int	ret;

	ret = divide_b(a, b);
	if (b->size == 2)
		rev_sort_2(a, b);
	if (b->size == 3)
		rev_sort_3(a, b);
	if (ret == 2)
		sort_2_a(a, b);
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
	ret = divide_a(a, b);
	sort_small_a(a, b);
	sort_small_b(a, b);
}

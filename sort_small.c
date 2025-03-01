/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:39:25 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/20 12:46:42 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_a(t_stack *a, t_stack *b, t_node *moves)
{
	int	ret;

	ret = divide_a(a, b, moves);
	if (a->size == 2)
		sort_2_a(a, b, moves);
	else if (a->size == 3)
		sort_3_a(a, b, moves);
	if (ret == 2)
		rev_sort_2_b(a, b, moves);
	else if (ret == 3)
		rev_sort_3_b(a, b, moves);
	while (ret--)
		add_move(moves, push(b, a, PA), a, b);
}

void	sort_small_b(t_stack *a, t_stack *b, t_node *moves)
{
	int	ret;

	ret = divide_b(a, b, moves);
	if (b->size == 2)
		rev_sort_2_b(a, b, moves);
	if (b->size == 3)
		rev_sort_3_b(a, b, moves);
	if (ret == 2)
		sort_2_a(a, b, moves);
	while (b->size)
		add_move(moves, push(b, a, PA), a, b);
}

void	sort_small(t_stack *a, t_stack *b, t_node *moves)
{
	int	ret;

	if (a->size <= 6)
	{
		sort_small_a(a, b, moves);
		return ;
	}
	ret = divide_a(a, b, moves);
	sort_small_a(a, b, moves);
	sort_small_b(a, b, moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_counters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:09:27 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 03:17:24 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_double_r(t_stack *main, t_stack *side, int value)
{
	int position_ret;
	int place_ret;

	position_ret = position(main->top, value);
	if (side->name == 'a')
	{
		place_ret = place_a(side, value);
	}
	else
	{
		place_ret = place_b(side, value);
	}
	if (position_ret > place_ret)
		return (position_ret);
	return (place_ret);
}

int	count_double_rr(t_stack *main, t_stack *side, int value)
{
	int position_ret;
	int place_ret;
	int	total;

	total = 0;
	position_ret = position(main->top, value);
	if (side->name == 'a')
		place_ret = place_a(side, value);
	else
		place_ret = place_b(side, value);
	if (place_ret)
		total = side->size - place_ret;
	if ((total < main->size - position_ret) && position_ret)
		total = main->size - position_ret;
	return (total);
}

int	count_rarrb(t_stack *main, t_stack *side, int value)
{
	int	position_ret;
	int	place_ret;
	int	total;

	total = 0;
	position_ret = position(main->top, value);
	if (side->name == 'a')
		place_ret = place_a(side, value);
	else
		place_ret = place_b(side, value);
	if (place_ret)
		total = side->size - place_ret;
	total += position_ret;
	return (total);
}

int	count_rrarb(t_stack *main, t_stack *side, int value)
{
	int	position_ret;
	int	place_ret;
	int	total;

	total = 0;
	position_ret = position(main->top, value);
	if (side->name == 'a')
		place_ret = place_a(side, value);
	else
		place_ret = place_b(side, value);
	if (position_ret)
		total = main->size - position_ret;
	total += place_ret;
	return (total);
}

int	count_all(t_stack *main, t_stack *side)
{
	int		count;
	t_node	*head;

	head = main->top;
	count = count_double_rr(main, side, head->value);
	while (head)
	{
		if (count > count_double_rr(main, side, head->value))
			count = count_double_rr(main, side, head->value);
		else if (count > count_double_r(main, side, head->value))
			count = count_double_r(main, side, head->value);
		else if (count > count_rarrb(main, side, head->value))
			count = count_rarrb(main, side, head->value);
		else if (count > count_rrarb(main, side, head->value))
			count = count_rrarb(main, side, head->value);
		head = head->next;
	}
	return (count);
}
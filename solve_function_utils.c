/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_function_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 06:29:30 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 15:31:35 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position(t_node *head, int value)
{
	int		ret;

	ret = 0;
	while (head->value != value)
	{
		head = head->next;
		ret++;
	}
	return (ret);
}

int	last_value(t_node *head)
{
	if (!head)
		return (-1);
	while (head->next)
		head = head->next;
	return (head->value);
}

int	place_a(t_stack *a, int value)
{
	t_node	*head;
	t_node	*p;
	int		ret;

	head = a->top;
	p = head->next;
	ret = 1;
	if (value < head->value && value > last_value(head))
		return (0);
	else if (value > get_max(head) || value < get_min(head))
		return (position(head, get_min(head)));
	else
	{
		while (head->value > value || value > p->value)
		{
			head = head->next;
			p = p->next;
			ret++;
		}
	}
	return (ret);
}

int	place_b(t_stack *b, int value)
{
	t_node	*head;
	t_node	*p;
	int		ret;

	head = b->top;
	p = head->next;
	ret = 1;
	if (value > head->value && value < last_value(head))
		return (0);
	else if (value > get_max(head) || value < get_min(head))
		return (position(head, get_max(head)));
	else
	{
		while (value > head->value || value < p->value)
		{
			head = head->next;
			p = p->next;
			ret++;
		}
	}
	return (ret);
}

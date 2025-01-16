/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:57:35 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 01:58:18 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stacks(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*head;

	if (a)
	{
		head = a->top;
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
	if (b)
	{
		head = b->top;
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
	a = NULL;
	b = NULL;
}

void	free_moves(t_node *moves)
{
	t_node	*tmp;
	t_node	*head;

	if (!moves)
		return ;
	head = moves->next;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
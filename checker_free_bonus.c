/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:41:59 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 18:37:52 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <stdio.h>

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

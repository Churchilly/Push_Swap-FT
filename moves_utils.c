/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:54:17 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 03:07:58 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	list_add_back(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (!head || !new_node)
		return ;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	add_move(t_node *moves, int move, t_stack *a, t_stack *b)
{
	t_node	*new;
	t_node	*tail;

	new = malloc(sizeof(t_node));
	if (!new)
		process_error("malloc error", a, b, moves);
	new->value = move;
	new->next = NULL;
	list_add_back(&moves, new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:54:17 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 18:38:57 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_moves(t_moves *moves)
{
	t_node	*tmp;
	t_node	*head;

	head = moves->a;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = moves->b;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	moves = NULL;
}

void list_add_back(t_node **head, t_node *new_node) {
    t_node *current;

    if (!head || !new_node)
        return;

    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void	add_move(t_moves *moves, int move, t_stack *a, t_stack *b)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		process_error("malloc error", a, b, moves);
	new->value = move;
	new->next = NULL;
	if (move < OP_A)
	{
		if (move == PA)
		{
			a->size -= 1;
			b->size += 1;
		}
		printf("%d\n", new->value);
		list_add_back(&moves->a, new);
		moves->total += 1;
	}
	else if (move < OP_B)
	{
		if (move == PB)
		{
			a->size += 1;
			b->size -= 1;
		}
		list_add_back(&moves->a, new);
		moves->total += 1;
	}
}

void	pop_move(t_node **move_list)
{
    t_node *node;

    if (!move_list || !*move_list)
        return ;
    node = *move_list;
    *move_list = node->next;
    node->next = NULL;
}
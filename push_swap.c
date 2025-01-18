/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/18 04:40:01 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	_init(t_stack *a, t_stack *b, t_node *moves)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	moves->value = NULL_OP;
	moves->next = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_node	moves;

	_init(&a, &b, &moves);
	insert_input(argc, argv, &a);
	solve(&a, &b, &moves);
	t_node *head = a.top;
	while (head)
	{
		printf("[[%d]]\n", head->value);
		head = head->next;
	}
	free_stacks(&a, &b);
	print_moves(&moves);
	free_moves(&moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:05 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	_init(t_stack *a, t_stack *b, t_node *moves)
{
	a->name = 'a';
	a->top = NULL;
	a->size = 0;
	b->name = 'b';
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
	free_stacks(&a, &b);
	print_moves(&moves);
	free_moves(&moves);
}

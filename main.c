/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 15:44:35 by yusudemi         ###   ########.fr       */
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
	print_moves(&moves);
	free_stacks(&a, &b);
	free_moves(&moves);
}

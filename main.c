/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 00:03:50 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_node	moves;
	t_node *head;

	a.top = NULL;
	b.top = NULL;
	a.size = 0;
	b.size = 0;
	moves.value = NULL_OP;
	moves.next = NULL;
	insert_input(argc, argv, &a);
	solve(&a,&b, &moves);
	print_moves(&moves);
	//free_moves(&moves);
	head = a.top;
	while (head)
	{
		printf("[%d]\n", head->value);
		head = head->next;
	}
	head = b.top;
	while (head)
	{
		printf("[%d]\n", head->value);
		head = head->next;
	}
	free_stacks(&a, &b);
}

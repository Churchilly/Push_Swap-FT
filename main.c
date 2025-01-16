/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/16 19:37:07 by yusudemi         ###   ########.fr       */
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
	a.name = 'a';
	b.name = 'b';
	moves.value = NULL_OP;
	moves.next = NULL;
	insert_input(argc, argv, &a);
	printf("fck\n");
	solve(&a,&b, &moves);
	printf("-%d-\n", moves.value);
	print_moves(&moves);
	//free_moves(&moves);
	printf("fuuuuuck\n");
	head = a.top;
	while (head)
	{
		printf("[%d]\n", head->value);
		head = head->next;
	}
	head = b.top;
	printf("size_a:%dxxxsize_b:%d\n", a.size, b.size);
	while (head)
	{
		printf("[%d]\n", head->value);
		head = head->next;
	}
	free_stacks(&a, &b);
}

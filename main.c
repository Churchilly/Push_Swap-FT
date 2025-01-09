/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/09 13:45:15 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_node *head;

	a.top = NULL;
	b.top = NULL;
	a.size = 0;
	b.size = 0;
	a.name = 'a';
	b.name = 'b';
	insert_input(argc, argv, &a);
	solve(&a,&b);

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
}

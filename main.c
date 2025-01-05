/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:07:46 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/05 20:46:55 by yusudemi         ###   ########.fr       */
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
	insert_input(argc, argv, &a);
	sort_stacks(&a,&b);

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

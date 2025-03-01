/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:47:45 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 18:38:16 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include <unistd.h>

static int	strcomp(char *str1, char *str2)
{
	if (!str1)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

static int	transform_operation(char *operation)
{
	if (strcomp("pa\n", operation))
		return (PA);
	if (strcomp("sa\n", operation))
		return (SA);
	if (strcomp("ra\n", operation))
		return (RA);
	if (strcomp("rra\n", operation))
		return (RRA);
	if (strcomp("pb\n", operation))
		return (PB);
	if (strcomp("sb\n", operation))
		return (SB);
	if (strcomp("rb\n", operation))
		return (RB);
	if (strcomp("rrb\n", operation))
		return (RRB);
	if (strcomp("ss\n", operation))
		return (SS);
	if (strcomp("rr\n", operation))
		return (RR);
	if (strcomp("rrr\n", operation))
		return (RRR);
}

static int	is_ok(t_stack *a, t_stack *b)
{
	t_node	*head;

	if (b->top)
		return (write(1, "KO\n", 3));
	head = a->top;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (write(1, "KO\n", 3), 0);
		head = head->next;
	}
	return (write(1, "OK\n", 3));
}

static void	_init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*operation;

	_init(&a, &b);
	insert_input(argc, argv, &a);
	operation = get_next_line(0);
	while (operation)
	{
		make_operation(&a, &b, transform_operation(operation));
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
	is_ok(&a, &b);
	free_stacks(&a, &b);
	return (0);
}

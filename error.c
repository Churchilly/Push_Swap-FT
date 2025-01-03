/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 06:28:36 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/03 06:36:42 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	error(char *message, t_stack *a)
{
	t_node	*tmp;
	char	*p;
	
	if (a)
	{
		while (a->top)
		{
			tmp = a->top->next;
			free(a->top);
			a->top = tmp;
		}
	}
	p = message;
	while (*p)
		p++;
	write(2, "Error\n", 6);
	write(2, message, p - message);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
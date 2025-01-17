/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 06:28:36 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 03:13:59 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	input_error(char *message, t_stack *a)
{
	t_node	*tmp;
	char	*p;

	free_stacks(a, NULL);
	p = message;
	while (*p)
		p++;
	write(2, "Error\n", 6);
	write(2, message, p - message);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	process_error(char *message, t_stack *a, t_stack *b, t_node *moves)
{
	char	*p;

	free_stacks(a, b);
	free_moves(moves);
	p = message;
	while (*p)
		p++;
	write(2, "Error\n", 6);
	write(2, message, p - message);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

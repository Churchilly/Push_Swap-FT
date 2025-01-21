/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:41:09 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 18:02:42 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
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

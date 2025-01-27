/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:37:02 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/27 19:15:03 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

static void	insert(int value, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		input_error("malloc error", stack);
	new->value = value;
	new->next = stack->top;
	stack->top = new;
}

static bool	is_num(char *str)
{
	if (*str == 0 || !str)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (false);
		str++;
	}
	return (true);
}

static bool	is_num_exist(int num, t_stack *a)
{
	t_node	*head;

	if (!a->top)
		return (false);
	head = a->top;
	while (head)
	{
		if (num == head->value)
			return (true);
		head = head->next;
	}
	return (false);
}

static void	push_numbers(char *input, t_stack *a)
{
	char	**splitted;
	int		i;
	int		num;

	if (!(*input))
		input_error("all must be number.", NULL);
	splitted = ft_split(input, ' ');
	if (!splitted || !(*splitted))
		free_split(splitted, "split error", a);
	i = 0;
	while (splitted[i])
		i++;
	while (--i >= 0)
	{
		if (!is_num(splitted[i]))
			free_split(splitted, "all must be number.", a);
		num = ft_atoi(splitted[i], a);
		if (is_num_exist(num, a))
			free_split(splitted, "numbers must not be duplicate.", a);
		insert(num, a);
	}
	free_split(splitted, NULL, NULL);
}

void	insert_input(int argc, char **argv, t_stack *a)
{
	int	num;

	if (argc < 2)
		input_error("Input must be more than zero", NULL);
	else if (argc == 2)
		push_numbers(argv[1], a);
	else
	{
		while (--argc > 0)
		{
			if (!is_num(argv[argc]))
				input_error("all must be number", a);
			num = ft_atoi(argv[argc], a);
			if (is_num_exist(num, a))
				input_error("numbers must be different than each other", a);
			insert(num, a);
		}
	}
}

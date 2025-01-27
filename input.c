/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:59:36 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/27 19:11:45 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

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

static void	free_split(char **split, char *message, t_stack *a)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (message && a)
		input_error(message, a);
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

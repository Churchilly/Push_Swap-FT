/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:46:58 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 15:31:52 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rarrb_a(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(a->top, value))
		add_move(moves, rotate(a, RA), a, b);
	while (place_b(b, value))
		add_move(moves, reverse_rotate(b, RRB), a, b);
	add_move(moves, push(a, b, PB), a, b);
	return (-1);
}

int	rrarb_a(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(a->top, value))
		add_move(moves, reverse_rotate(a, RRA), a, b);
	while (place_b(b, value))
		add_move(moves, rotate(b, RB), a, b);
	add_move(moves, push(a, b, PB), a, b);
	return (-1);
}

int	rarrb_b(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(b->top, value))
		add_move(moves, reverse_rotate(b, RRB), a, b);
	while (place_a(a, value))
		add_move(moves, rotate(a, RA), a, b);
	add_move(moves, push(b, a, PA), a, b);
	return (-1);
}

int	rrarb_b(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(b->top, value))
		add_move(moves, rotate(b, RB), a, b);
	while (place_a(a, value))
		add_move(moves, reverse_rotate(a, RRA), a, b);
	add_move(moves, push(b, a, PA), a, b);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_double_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:57:38 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 02:15:40 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_rotate_a(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(a->top, value) && place_b(b, value))
	{
		add_move(moves, rotate(a, RA), a, b);
		add_move(moves, rotate(b, RB), a, b);
	}
	while (position(a->top, value))
		add_move(moves, rotate(a, RA), a, b);
	while (place_b(b, value))
		add_move(moves, rotate(b, RB), a, b);
	add_move(moves, push(a, b, PB), a, b);	
	return (-1);
}

int	double_reverse_rotate_a(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(a->top, value) && place_b(b, value))
	{
		add_move(moves, reverse_rotate(a, RRA), a, b);
		add_move(moves, reverse_rotate(b, RRB), a, b);
	}
	while (position(a->top, value))
		add_move(moves, reverse_rotate(a, RRA), a, b);
	while (place_b(b, value))
		add_move(moves, reverse_rotate(b, RRB), a, b);
	add_move(moves, push(a, b, PB), a, b);	
	return (-1);
}

int	double_rotate_b(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(b->top, value) && place_a(a, value))
	{
		add_move(moves, rotate(a, RA), a, b);
		add_move(moves, rotate(b, RB), a, b);
	}
	while (position(b->top, value))
		add_move(moves, rotate(b, RB), a, b);
	while (place_a(a, value))
		add_move(moves, rotate(a, RA), a, b);
	add_move(moves, push(b, a, PA), a, b);
	return (-1);
}

int	double_reverse_rotate_b(t_stack *a, t_stack *b, t_node *moves, int value)
{
	while (position(b->top, value) && place_a(a, value))
	{
		add_move(moves, reverse_rotate(a, RRA), a, b);
		add_move(moves, reverse_rotate(b, RRB), a, b);
	}
	while (position(b->top, value))
		add_move(moves, reverse_rotate(b, RRB), a, b);
	while (place_a(a, value))
		add_move(moves, reverse_rotate(a, RRA), a, b);
	add_move(moves, push(b, a, PA), a, b);	
	return (-1);
}

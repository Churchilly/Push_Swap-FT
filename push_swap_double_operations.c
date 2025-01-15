/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_double_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:12:32 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/15 17:15:46 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a, NULL_OP);
	swap(b, NULL_OP);
}
void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a, RR);
	rotate(b, NULL_OP);
}
void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, RRR);
	reverse_rotate(b, NULL_OP);
}

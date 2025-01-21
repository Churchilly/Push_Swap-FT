/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:17 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/21 15:18:09 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define PA 1
# define SA 2
# define RA 3
# define RRA 4
# define PB 6
# define SB 7
# define RB 8
# define RRB 9
# define SS 11
# define RR 12
# define RRR 13

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

void	insert_input(int argc, char **argv, t_stack *a);
void	make_operation(t_stack *a, t_stack *b, int operation);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_atoi_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:42:39 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/27 20:42:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "checker_bonus.h"

static int	check_sign(const char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, t_stack *a)
{
	int		sign;
	long	num;
	int		prefix;

	sign = 1;
	num = 0;
	prefix = 0;
	while (*str == 9 || *str == 10 || *str == 11
		|| *str == 12 || *str == 13 || *str == 32)
		str++;
	prefix = check_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num * sign > INT_MAX)
			input_error("Input must be smaller than INT_MAX", a);
		if (num * sign < INT_MIN)
			input_error("Input must be biffer than INT_MIN", a);
		str++;
	}
	if (prefix && num == 0)
		input_error("Invalid input", a);
	return ((int)(num * sign));
}

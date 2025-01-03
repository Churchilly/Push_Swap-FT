#include <limits.h>
#include "push_swap.h"

int	ft_atoi(const char *str, t_stack *a)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*str == 9 || *str == 10 || *str == 11
			|| *str == 12 || *str == 13 || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num * sign > INT_MAX)
			error("Input must be smaller than INT_MAX", a);
		if (num * sign < INT_MIN)
			error("Input must be biffer than INT_MIN", a);
		str++;
	}
	return ((int)(num * sign));
}
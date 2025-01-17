/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:51:10 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/17 02:18:49 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;

	pivot = arr[high];
	i = low - 1;
	while (low <= high - 1)
	{
		if (arr[low] < pivot)
		{
			i++;
			swap(&arr[i], &arr[low]);
		}
		low++;
	}
	swap (&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ft_qsort(int arr[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		ft_qsort(arr, low, pivot - 1);
		ft_qsort(arr, pivot + 1, high);
	}
}

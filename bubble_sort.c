/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinchen <jinchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:52:45 by jinchen           #+#    #+#             */
/*   Updated: 2026/02/07 21:49:21 by jinchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "utils.h"
#include "free.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int	*copy_into_sorted(int *arr, int size)
{
	int	*sorted;
	int	i;

	i = -1;
	sorted = malloc(size * sizeof(int));
	if (!sorted)
	{
		free(arr);
		error_message("Error\n");
	}
	while (++i < size)
		sorted[i] = arr[i];
	bubble_sort(sorted, size);
	return (sorted);
}

bool	is_sorted(int *unordered, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		return (true);
	while (++i < size)
	{
		if (unordered[i] < unordered[i - 1])
			return (false);
	}
	return (true);
}

int	*get_nums(char **av, int nums_count)
{
	int		*nums;
	char	**temp;
	int		idx[3];

	idx[0] = 0;
	idx[2] = -1;
	nums = malloc(nums_count * sizeof(int));
	if (!nums)
		error_message("Error\n");
	while (av[++idx[0]])
	{
		temp = ft_split(av[idx[0]], ' ');
		if (!temp)
			error_message("Error\n");
		else if (temp[0] == NULL)
			free_matrix(temp, 1);
		else
		{
			idx[1] = -1;
			while (temp[++idx[1]])
				nums[++idx[2]] = ft_atoi(temp[idx[1]]);
			free_matrix(temp, get_matrix_size(temp));
		}
	}
	return (nums);
}

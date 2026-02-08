/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinchen <jinchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:15:43 by jinchen           #+#    #+#             */
/*   Updated: 2026/02/07 21:51:42 by jinchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortings.h"
#include "ft_printf.h"
#include "stack_actions.h"
#include "butterfly.h"
#include "free.h"

void	double_sort(int *unordered, int *sorted)
{
	ft_printf("sa\n");
	free(unordered);
    free(sorted);
}

void	triple_sort(t_stack *st_a)
{
	int	arr[3];

	arr[0] = st_a->head->index;
	arr[1] = st_a->head->next->index;
	arr[2] = st_a->head->next->next->index;
	if (arr[0] == 0 && arr[1] == 2)
	{
		reverse_rotate_stack(st_a, "rra");
		swap_stack(st_a, "sa");
	}
	else if (arr[0] == 0 && arr[1] == 1)
		return ;
	else if (arr[0] == 1 && arr[1] == 0)
		swap_stack(st_a, "sa");
	else if (arr[0] == 1 && arr[1] == 2)
		reverse_rotate_stack(st_a, "rra");
	else if (arr[0] == 2 && arr[1] == 0)
		rotate_stack(st_a, "ra");
	else if (arr[0] == 2 && arr[1] == 1)
	{
		swap_stack(st_a, "sa");
		reverse_rotate_stack(st_a, "rra");
	}
}

void	fourple_sort(t_stack *st_a, t_stack *st_b, int size)
{
	t_lst	*lst;

	lst = st_a->head;
	find_max_and_push_b(lst, st_a, size);
	push_stack(st_a, st_b, "pb");
	triple_sort(st_a);
	push_stack(st_b, st_a, "pa");
	rotate_stack(st_a, "ra");
}

void	fiveple_sort(t_stack *st_a, t_stack *st_b, int size)
{
	t_lst	*lst;

	lst = st_a->head;
	find_max_and_push_b(lst, st_a, size);
	push_stack(st_a, st_b, "pb");
	fourple_sort(st_a, st_b, size - 1);
	push_stack(st_b, st_a, "pa");
	rotate_stack(st_a, "ra");
}

void	small_stack_sort(t_stack *st_a, t_stack *st_b, int size)
{
	if (size == 3)
		triple_sort(st_a);
	else if (size == 4)
		fourple_sort(st_a, st_b, size);
	else if (size == 5)
		fiveple_sort(st_a, st_b, size);
}

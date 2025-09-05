/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:47:02 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 12:30:29 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack_a)
{
	int		min;
	t_node	*current;
	t_node	*tmp;

	current = stack_a;
	min = current->index;
	tmp = current;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_node *stack_a)
{
	int		max;
	t_node	*current;
	t_node	*tmp;

	current = stack_a;
	max = current->index;
	tmp = current;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_insert_pos(t_node *stack_a, int index_top_b)
{
	const int	min = find_min(stack_a);
	const int	max = find_max(stack_a);
	int			pos;
	t_node		*current;

	pos = 0;
	current = stack_a;
	if (index_top_b < min || index_top_b > max)
	{
		while (current->index != max)
		{
			pos++;
			current = current->next;
		}
		return (pos);
	}
	while (current && current->next)
	{
		if (index_top_b < current->index && index_top_b > current->next->index)
			return (pos + 1);
		pos++;
		current = current->next;
	}
	return (0);
}

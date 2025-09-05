/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:03:58 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 12:06:44 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abso_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	calculate_costs(t_node *stack_a, t_node *stack_b)
{
	int		pos_b;
	int		pos_a;
	t_node	*tmp_b;

	pos_b = 0;
	tmp_b = stack_b;
	pos_a = find_insert_pos(stack_a, tmp_b->index);
	while (tmp_b)
	{
		if (pos_b <= (ft_lstsize(stack_b) / 2))
			tmp_b->cost_b = pos_b;
		else
			tmp_b->cost_b = pos_b - ft_lstsize(stack_b);
		pos_a = find_insert_pos(stack_a, tmp_b->index);
		if (pos_a <= (ft_lstsize(stack_a) / 2))
			tmp_b->cost_a = pos_a;
		else
			tmp_b->cost_a = pos_a - ft_lstsize(stack_a);
		tmp_b->total_cost = abso_val(tmp_b->cost_a) + abso_val(tmp_b->cost_b);
		pos_b++;
		tmp_b = tmp_b->next;
	}
}

t_node	*find_cheapest_move(t_node *stack_b)
{
	t_node	*cheapest;
	t_node	*tmp;

	cheapest = stack_b;
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->total_cost < cheapest->total_cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	do_rotate(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rot_a_b(stack_a, stack_b, true);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rev_rot_a_b(stack_a, stack_b, true);
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a > 0)
	{
		rot_a(stack_a, true);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rev_rot_a(stack_a, true);
		(*cost_a)++;
	}
}

void	execute_move(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	do_rotate(stack_a, stack_b, &cost_a, &cost_b);
	while (cost_b > 0)
	{
		rot_b(stack_b, true);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rev_rot_b(stack_b, true);
		cost_b++;
	}
	push_a(stack_a, stack_b, true);
}

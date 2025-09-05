/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:41:13 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 12:19:09 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_stack(t_node *stack)
{
	int	size;

	size = ft_lstsize(stack);
	return (size / 1.25);
}

void	insert_in_a(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	size;

	pos = find_insert_pos(*stack_a, (*stack_b)->index);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			rot_a(stack_a, true);
	else
		while (pos++ < size)
			rev_rot_a(stack_a, true);
	push_a(stack_a, stack_b, true);
}

void	final_rotate(t_node **stack_a)
{
	int		max_pos;
	int		max_index;
	int		size;
	t_node	*tmp;

	max_pos = 0;
	max_index = find_max(*stack_a);
	size = ft_lstsize(*stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == max_index)
			break ;
		max_pos++;
		tmp = tmp->next;
	}
	if (max_pos <= size / 2)
		while (max_pos-- > 0)
			rot_a(stack_a, true);
	else
		while (max_pos++ < size)
			rev_rot_a(stack_a, true);
}

void	step_one(t_node **stack_a, t_node **stack_b)
{
	int		median;
	bool	pushed;
	int		current_size;
	int		checked;

	while (ft_lstsize(*stack_a) > 3)
	{	
		median = median_stack(*stack_a);
		checked = 0;
		pushed = false;
		current_size = ft_lstsize(*stack_a);
		while (checked < current_size)
		{
			if ((*stack_a)->index >= median)
			{
				push_b(stack_b, stack_a, true);
				pushed = true;
			}
			else
				rot_a(stack_a, true);
			checked++;
		}
		if (!pushed)
			break ;
	}
}

void	push_swap_algo(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;

	step_one(stack_a, stack_b);
	sort_three_val(stack_a);
	while (*stack_b)
	{
		calculate_costs(*stack_a, *stack_b);
		best = find_cheapest_move(*stack_b);
		execute_move(stack_a, stack_b, best);
	}
	final_rotate(stack_a);
}

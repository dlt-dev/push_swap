/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:36:41 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 11:57:17 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three_val(t_node **stack)
{
	t_node	*biggest;

	biggest = find_biggest(*stack);
	if (biggest == *stack)
		rot_a(stack, true);
	else if ((*stack)->next == biggest)
		rev_rot_a(stack, true);
	if ((*stack)->index < (*stack)->next->index)
		swap_a(stack, true);
}

void	under_one_fifty(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;

	while (ft_lstsize(*stack_a) > 3)
	{
		push_b(stack_b, stack_a, true);
	}
	sort_three_val(stack_a);
	while (*stack_b)
	{
		calculate_costs(*stack_a, *stack_b);
		best = find_cheapest_move(*stack_b);
		execute_move(stack_a, stack_b, best);
	}
	final_rotate(stack_a);
}

t_node	*find_last(t_node *stack)
{
	t_node	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_node	*find_biggest(t_node *stack)
{
	t_node	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->index < biggest->index)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

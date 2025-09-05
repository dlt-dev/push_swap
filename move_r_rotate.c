/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:22:43 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/25 12:22:53 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(t_node **stack, bool print)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	before_last = last->prev;
	if (before_last)
		before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rev_rot_b(t_node **stack, bool print)
{
	rev_rot_a(stack, false);
	if (print)
		write(1, "rrb\n", 4);
}

void	rev_rot_a_b(t_node **stack_a, t_node **stack_b, bool print)
{
	rev_rot_a(stack_a, false);
	rev_rot_b(stack_b, false);
	if (print)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:03:12 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/25 12:22:16 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_node **stack, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	if (*stack)
		(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rot_b(t_node **stack, bool print)
{
	rot_a(stack, false);
	if (print)
		write(1, "rb\n", 3);
}

void	rot_a_b(t_node **stack_a, t_node **stack_b, bool print)
{
	rot_a(stack_a, false);
	rot_b(stack_b, false);
	if (print)
		write(1, "rr\n", 3);
}

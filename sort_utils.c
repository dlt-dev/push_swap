/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:59:17 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/25 12:14:02 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_node **stack, bool print)
{
	swap_a(stack, false);
	if (print)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_node **stack_a, t_node **stack_b, bool print)
{
	swap_a(stack_a, false);
	swap_b(stack_b, false);
	if (print)
		write(1, "sb\n", 3);
}

void	push_a(t_node **stack_a, t_node **stack_b, bool print)
{
	t_node	*to_move;

	if (!stack_b || !*stack_b)
		return ;
	to_move = *stack_b;
	*stack_b = to_move->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	to_move->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = to_move;
	to_move->prev = NULL;
	*stack_a = to_move;
	if (print)
		write(1, "pa\n", 3);
}

void	push_b(t_node **stack_b, t_node **stack_a, bool print)
{
	t_node	*to_move;

	if (!stack_a || !*stack_a)
		return ;
	to_move = *stack_a;
	*stack_a = to_move->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	to_move->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = to_move;
	to_move->prev = NULL;
	*stack_b = to_move;
	if (print)
		write(1, "pb\n", 3);
}

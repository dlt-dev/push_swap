/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:06:18 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 11:54:35 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack(int *int_tab, int size)
{
	t_node	*my_stack;
	int		i;

	i = 0;
	my_stack = NULL;
	while (i < size)
	{
		push(&my_stack, int_tab[i]);
		i++;
	}
	return (my_stack);
}

void	my_index(t_node *stack)
{
	t_node	*current;
	t_node	*to_check;
	int		index_to_give;

	current = stack;
	while (current)
	{
		index_to_give = 0;
		to_check = stack;
		while (to_check)
		{
			if (to_check->value > current->value)
				index_to_give++;
			to_check = to_check->next;
		}
		current->index = index_to_give;
		current = current->next;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

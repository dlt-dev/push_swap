/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:53:53 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 11:55:11 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int arg_val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = arg_val;
	node->index = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->total_cost = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_node **stack, int arg_val)
{
	t_node	*new;
	t_node	*current;

	new = ft_lstnew(arg_val);
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}

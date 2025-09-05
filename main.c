/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:54:58 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 12:03:18 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init(int ac, char **av, int *error)
{
	t_node	*stack_a;
	int		*int_tab;
	char	**tab_args;

	int_tab = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
		tab_args = split_args(av[1]);
	else
		tab_args = &av[1];
	int_tab = convert_valid_int(tab_args, count_args(tab_args), error);
	if (*error)
	{
		free(int_tab);
		if (ac == 2)
			ft_freesplit(tab_args, count_args(tab_args));
		return (NULL);
	}
	stack_a = create_stack(int_tab, count_args(tab_args));
	my_index(stack_a);
	free(int_tab);
	if (ac == 2)
		ft_freesplit(tab_args, count_args(tab_args));
	return (stack_a);
}

int	main(int ac, char **av)
{
	int		error;
	t_node	*stack_a;
	t_node	*stack_b;

	error = 0;
	stack_b = NULL;
	stack_a = init(ac, av, &error);
	if (error)
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			swap_a(&stack_a, true);
		else if (ft_lstsize(stack_a) <= 150)
			under_one_fifty(&stack_a, &stack_b);
		else
			push_swap_algo(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	return (0);
}

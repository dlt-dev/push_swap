/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:52:21 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/25 12:37:46 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_check(char **tab_args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_args[i])
	{
		j = 0;
		if (tab_args[i][j] == '-' || tab_args[i][j] == '+')
				j++;
		if (tab_args[i][j] == '\0')
			return (1);
		while (tab_args[i][j])
		{
			if (tab_args[i][j] < '0' || tab_args[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*convert_valid_int(char **tab_args, int count_ar, int *error)
{
	int		*int_tab;
	long	i;

	i = 0;
	while (tab_args[i])
		i++;
	int_tab = malloc(sizeof(int) * (i + 1));
	i = 0;
	if (!int_tab)
		return (NULL);
	while (tab_args[i])
	{
		int_tab[i] = ft_atol_secure(tab_args[i], error);
		i++;
	}
	if ((valid_check(tab_args) == 0) && (twins_check(int_tab, count_ar) == 0))
		return (int_tab);
	free(int_tab);
	*error = 1;
	return (0);
}

int	how_many_twins(int *int_tab, int to_check, int count_ar)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < count_ar)
	{
		if (int_tab[i] == to_check)
			count++;
		i++;
	}
	return (count);
}

int	twins_check(int *int_tab, int count_ar)
{
	int	i;

	i = 0;
	while (i < count_ar)
	{
		if (how_many_twins(int_tab, int_tab[i], count_ar) > 1)
			return (1);
		i++;
	}
	return (0);
}

int	count_args(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

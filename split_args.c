/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:45:55 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/25 11:54:18 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"// 5

int	count_data(const char *str)
{
	int	i;
	int	count;
	int	in_data;

	i = 0;
	count = 0;
	in_data = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			in_data = 0;
		if (str[i] != ' ' && in_data == 0)
		{
			in_data = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_allocsplit(int count_data)
{
	int		i;
	char	**split;

	i = 0;
	split = malloc(sizeof(char *) * (count_data + 1));
	if (!split)
		return (NULL);
	while (i < count_data + 1)
	{
		split[i] = NULL;
		i++;
	}
	return (split);
}

char	**ft_freesplit(char **split, int j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
	return (0);
}

char	**ft_fillsplit(char **split, char const *str)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i > start)
		{
			split[j] = ft_substr(str, start, i - start);
			if (split[j] == 0)
				return (ft_freesplit(split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**split_args(char const *str)
{
	char	**split;
	int		wordcount;

	wordcount = count_data(str);
	split = ft_allocsplit(wordcount);
	if (!split)
		return (NULL);
	split = ft_fillsplit(split, str);
	return (split);
}

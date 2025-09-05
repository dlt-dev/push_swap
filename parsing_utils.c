/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:03 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/19 19:57:29 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == source || size == 0)
		return (dest);
	while (i < size)
	{
		((char *)dest)[i] = ((char *)source)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		lenght;
	char	*m;
	int		i;

	i = 0;
	lenght = ft_strlen(s);
	m = malloc(sizeof(char) * (lenght + 1));
	if (m == 0)
		return (0);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	maxlen;
	size_t	sublen;
	char	*sub;

	if (!s)
		return (NULL);
	maxlen = ft_strlen(s);
	if (start >= maxlen)
		return (ft_strdup(""));
	if (start + len > maxlen)
		sublen = maxlen - start;
	else
		sublen = len;
	sub = malloc(sizeof(char) * (sublen + 1));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, sublen);
	sub[sublen] = '\0';
	return (sub);
}

long	ft_atol_secure(const char *str, int *error)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
		{
			*error = 1;
		}
		i++;
	}
	return (res * sign);
}

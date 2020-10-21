/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:18:47 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 19:54:59 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_index_of(char c, char const *set)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	ft_get_new_size(char const *s1, char const *set)
{
	size_t size;
	size_t i;

	if (!s1 || !set)
		return (0);
	size = ft_strlen(s1) + 1;
	i = 0;
	while (s1[i] && ft_index_of(s1[i++], set) != -1)
	{
		size--;
	}
	if (i == ft_strlen(s1))
		return (0);
	i = ft_strlen(s1) - 1;
	while (ft_index_of(s1[i--], set) != -1)
	{
		size--;
	}
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*ret;
	size_t	i;
	int		current;

	if (!s1 || !set)
		return (NULL);
	size = ft_get_new_size(s1, set);
	if (!(ret = malloc(size * sizeof(char))))
		return (NULL);
	i = 0;
	current = 0;
	while (ft_index_of(s1[i], set) != -1)
	{
		i++;
	}
	while (current < size - 1)
	{
		ret[current++] = s1[i++];
	}
	ret[current] = 0;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:02:31 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/12 17:30:15 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!haystack && !len)
		return (0);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len && len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			if (!(needle[j + 1]))
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

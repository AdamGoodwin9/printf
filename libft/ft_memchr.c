/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:11:22 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/11 17:52:25 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		find;
	const unsigned char	*ptr;

	find = c;
	ptr = s;
	while (n--)
	{
		if (*ptr == find)
		{
			return (void*)(ptr);
		}
		ptr++;
	}
	return (NULL);
}

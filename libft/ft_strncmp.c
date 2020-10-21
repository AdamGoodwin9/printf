/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:43:15 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/12 17:51:54 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *u1;
	const unsigned char *u2;
	size_t				i;

	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	i = 0;
	while (i < n && *u1 && *u2)
	{
		if (*u1 != *u2)
		{
			return (*u1 - *u2);
		}
		u1++;
		u2++;
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (*u1 - *u2);
}

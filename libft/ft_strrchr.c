/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:56:42 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/11 15:54:23 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (1)
	{
		if (*s == c)
		{
			ret = s;
		}
		if (*s == 0)
		{
			break ;
		}
		s++;
	}
	return (char*)(ret);
}

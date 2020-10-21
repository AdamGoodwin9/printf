/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:35:02 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/11 15:51:50 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (1)
	{
		if (*s == c)
		{
			ret = s;
			break ;
		}
		if (*s == 0)
		{
			break ;
		}
		s++;
	}
	return (char*)(ret);
}

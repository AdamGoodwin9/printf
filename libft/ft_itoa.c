/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:13:10 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 19:22:25 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int size;

	size = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	return (n < 0 ? size + 1 : size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*ret;

	size = ft_get_size(n);
	if (!(ret = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ret[size] = 0;
	if (n < 0)
		ret[0] = '-';
	while (n >= 10 || n <= -10)
	{
		ret[--size] = (n < 0 ? (n % 10) * -1 : n % 10) + '0';
		n /= 10;
	}
	ret[--size] = (n < 0 ? n * -1 : n) + '0';
	return (ret);
}

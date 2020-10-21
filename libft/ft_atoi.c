/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:04:22 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/12 15:50:52 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_index_of(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		is_neg;
	char	*base;

	base = "0123456789";
	result = 0;
	i = 0;
	is_neg = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		is_neg = str[i++] == '-' ? !is_neg : is_neg;
	while (ft_index_of(str[i], base) >= 0)
	{
		result *= ft_strlen(base);
		result += ft_index_of(str[i], base);
		i++;
	}
	return (is_neg ? -result : result);
}

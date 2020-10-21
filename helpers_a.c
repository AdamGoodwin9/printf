/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:29:30 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 18:18:43 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int					ft_check_negative(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		return (1);
	}
	return (0);
}

int					ft_strnlen(char *str, int n)
{
	int count;

	count = 0;
	while (*str++ && count < n)
	{
		count++;
	}
	return (count);
}

unsigned long long	ft_pow(int base, int exp)
{
	int					i;
	unsigned long long	result;

	if (exp == 0)
	{
		return (1);
	}
	i = 1;
	result = (unsigned long long)base;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

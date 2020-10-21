/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:07:14 by agoodwin          #+#    #+#             */
/*   Updated: 2019/11/21 18:13:49 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_get_digit_count(int nb)
{
	int digits;

	digits = 1;
	while (nb >= 10)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

static int	ft_pow(int base, int exp)
{
	int i;
	int result;

	if (exp == 0)
	{
		return (1);
	}
	i = 1;
	result = base;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

static int	ft_check_negative(int nb, int fd)
{
	char neg;

	if (nb < 0)
	{
		neg = '-';
		write(fd, &neg, 1);
		return (nb * -1);
	}
	return (nb);
}

int			ft_putnbr_fd(int n, int fd)
{
	int		temp;
	int		digits;
	int		i;
	char	result;

	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	n = ft_check_negative(n, fd);
	digits = ft_get_digit_count(n);
	temp = n;
	i = 0;
	while (i < digits)
	{
		temp = (n / ft_pow(10, digits - i - 1)) % 10;
		result = '0' + temp;
		write(fd, &result, 1);
		i++;
	}
	return (digits);
}

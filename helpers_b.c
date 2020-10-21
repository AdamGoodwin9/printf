/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:35:43 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 17:55:31 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_get_digit_count(unsigned long long nb, int base, int prec)
{
	int digits;

	digits = 0;
	while (nb > 0)
	{
		digits++;
		nb /= base;
	}
	if (prec && !digits)
		digits = 1;
	return (digits);
}

int		ft_potstir_fd(char *stir, int fd, t_pad_meta pad)
{
	int		count;
	int		len;

	if (stir == NULL)
		stir = "(null)";
	if (pad->prec != -1)
		len = ft_strnlen(stir, pad->prec);
	else
		len = ft_strlen(stir);
	count = ft_print_pre_padding(fd, pad, len);
	if (len > 0)
	{
		count += (write(fd, stir, len));
	}
	return (count);
}

int		ft_putchr_fd(char c, int fd, t_pad_meta pad)
{
	int		count;

	count = ft_print_pre_padding(fd, pad, 1);
	count++;
	write(fd, &c, 1);
	return (count);
}

int		ft_putunsigned_fd(unsigned int n, int fd, t_pad_meta pad)
{
	int		count;
	int		temp;
	int		digits;
	int		i;
	char	result;

	digits = ft_get_digit_count(n, 10, pad->prec);
	count = digits;
	i = pad->prec - digits;
	if (i > 0)
		count = pad->prec;
	count += ft_print_pre_padding(fd, pad, count);
	while (i-- > 0)
		write(fd, "0", 1);
	i = 0;
	while (i < digits)
	{
		temp = (int)((n / ft_pow(10, digits - i - 1)) % 10);
		result = '0' + temp;
		write(fd, &result, 1);
		i++;
	}
	return (count);
}

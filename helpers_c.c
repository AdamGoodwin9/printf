/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:16:51 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 18:21:27 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_trash(t_trash t)
{
	while (t->i-- > 0)
		write(t->fd, "0", 1);
	t->n = ft_max(t->n, -t->n);
	if (t->n == -2147483648)
		write(t->fd, "2147483648", 10);
	t->i = 0;
	while (t->i < t->digits && t->n != -2147483648)
	{
		t->result = '0' + (t->n / ft_pow(10, t->digits - t->i - 1)) % 10;
		write(t->fd, &t->result, 1);
		t->i++;
	}
}

int		ft_putint_fd(int n, int fd, t_pad_meta pad)
{
	struct s_trash s;

	s.n = n;
	s.fd = fd;
	s.digits = ft_get_digit_count_signed(ft_max(s.n, -s.n), 10, pad->prec);
	s.count = s.digits;
	s.i = pad->prec - s.digits;
	if (s.i > 0)
		s.count = pad->prec;
	if (n < 0)
		s.count += 1;
	if (pad->pad_mode == 2)
		ft_check_negative(s.n, s.fd);
	s.count += ft_print_pre_padding(s.fd, pad, s.count);
	if (pad->pad_mode != 2)
		ft_check_negative(s.n, s.fd);
	ft_trash(&s);
	return (s.count);
}

int		ft_putptr_fd(unsigned long long n, int fd, t_pad_meta pad)
{
	int		count;
	int		temp;
	int		digits;
	int		i;
	char	*alpha;

	alpha = "0123456789abcdef";
	digits = ft_get_digit_count(n, 16, pad->prec);
	count = digits + 2;
	i = pad->prec - digits;
	if (i > 0)
		count = pad->prec + 2;
	count += ft_print_pre_padding(fd, pad, count);
	write(fd, "0x", 2);
	while (i-- > 0)
		write(fd, "0", 1);
	i = 0;
	while (i < digits)
	{
		temp = (int)((n / ft_pow(16, digits - i - 1)) % 16);
		write(fd, alpha + temp, 1);
		i++;
	}
	return (count);
}

int		ft_puthex_fd(unsigned long long n, int fd, t_pad_meta pad)
{
	int		count;
	int		temp;
	int		digits;
	int		i;
	char	*alpha;

	alpha = "0123456789abcdef";
	digits = ft_get_digit_count(n, 16, pad->prec);
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
		temp = (int)((n / ft_pow(16, digits - i - 1)) % 16);
		write(fd, alpha + temp, 1);
		i++;
	}
	return (count);
}

int		ft_putuhex_fd(unsigned long long n, int fd, t_pad_meta pad)
{
	int		count;
	int		temp;
	int		digits;
	int		i;
	char	*alpha;

	alpha = "0123456789ABCDEF";
	digits = ft_get_digit_count(n, 16, pad->prec);
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
		temp = (int)((n / ft_pow(16, digits - i - 1)) % 16);
		write(fd, alpha + temp, 1);
		i++;
	}
	return (count);
}

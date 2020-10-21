/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 04:34:06 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 18:20:40 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_pre_padding(int fd, t_pad_meta pad, int count)
{
	char	pad_char;
	int		pad_count;
	int		i;

	i = 0;
	pad_count = 0;
	pad_char = ' ';
	if (pad->pad_mode == 0 || pad->pad_mode == 2)
	{
		if (pad->padding > count)
			pad_count = pad->padding - count;
		if (pad->pad_mode == 2)
			pad_char = '0';
		while (i++ < pad_count)
			write(fd, &pad_char, 1);
	}
	return (pad_count);
}

int	ft_print_post_padding(int fd, t_pad_meta pad, int count)
{
	int pad_count;
	int i;

	i = 0;
	pad_count = 0;
	if (pad->pad_mode == 1)
	{
		if (pad->padding > count)
			pad_count = pad->padding - count;
		while (i++ < pad_count)
			write(fd, " ", 1);
	}
	return (pad_count);
}

int	ft_get_digit_count_signed(long long nb, int base, int prec)
{
	int digits;

	if (nb == -2147483648)
		return (10);
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

int	ft_handle_flag(const char **str, va_list *a)
{
	struct s_pad_meta	p;
	int					c;

	ft_get_pad(str, &p, a);
	c = 0;
	if (**str == 's')
		c = ft_potstir_fd(va_arg(*a, char *), 1, &p);
	else if (**str == 'd' || **str == 'i')
		c = ft_putint_fd(va_arg(*a, int), 1, &p);
	else if (**str == 'c')
		c = ft_putchr_fd((char)va_arg(*a, int), 1, &p);
	else if (**str == 'p')
		c = ft_putptr_fd((unsigned long long)va_arg(*a, void *), 1, &p);
	else if (**str == 'u')
		c = ft_putunsigned_fd(va_arg(*a, unsigned int), 1, &p);
	else if (**str == 'x')
		c = ft_puthex_fd((unsigned long long)va_arg(*a, unsigned int), 1, &p);
	else if (**str == 'X')
		c = ft_putuhex_fd(va_arg(*a, unsigned int), 1, &p);
	else if (**str == '%')
		c = ft_print_pre_padding(1, &p, 1) + ft_putchar_fd('%', 1);
	else if (**str == '\0')
		return (c);
	(*str)++;
	return (c + ft_print_post_padding(1, &p, c));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_handle_flag(&str, &args);
			continue ;
		}
		write(1, str, 1);
		count++;
		str++;
	}
	va_end(args);
	return (count);
}

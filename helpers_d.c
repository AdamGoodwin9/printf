/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:56:00 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 18:07:17 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_get_pad_mode(const char **str)
{
	int pad_mode;

	pad_mode = 0;
	while (**str == '0' || **str == '-')
	{
		if (**str == '0')
		{
			if (pad_mode == 0)
				pad_mode = 2;
		}
		if (**str == '-')
		{
			pad_mode = 1;
		}
		(*str)++;
	}
	return (pad_mode);
}

int		ft_get_padding(const char **str)
{
	int padding;

	padding = 0;
	if (**str >= '1' && **str <= '9')
	{
		padding = ft_atoi(*str);
		(*str) += ft_get_digit_count(padding, 10, 1);
	}
	return (padding);
}

int		ft_get_prec(const char **str, int prec)
{
	if (**str >= '0' && **str <= '9')
		prec = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
	return (prec);
}

void	ft_get_pad_helper(const char **str, t_pad_meta meta, va_list *args)
{
	int a;

	meta->pad_mode = ft_get_pad_mode(str);
	if (**str == '*')
	{
		a = va_arg(*args, int);
		if (a < 0)
		{
			a = -a;
			meta->pad_mode = 1;
		}
		if (a == 0 && meta->pad_mode == 0)
			meta->pad_mode = 2;
		meta->padding = a;
		(*str)++;
	}
	else
		meta->padding = ft_get_padding(str);
	meta->prec = -1;
}

void	ft_get_pad(const char **str, t_pad_meta meta, va_list *args)
{
	ft_get_pad_helper(str, meta, args);
	if (**str == '.')
	{
		meta->prec = 0;
		(*str)++;
		if (**str == '*')
		{
			meta->prec = va_arg(*args, int);
			if (meta->prec < 0)
			{
				meta->prec = -1;
			}
			(*str)++;
		}
		else
			meta->prec = ft_get_prec(str, meta->prec);
	}
	if (meta->pad_mode == 2 && meta->prec >= 0)
		meta->pad_mode = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 04:37:15 by agoodwin          #+#    #+#             */
/*   Updated: 2020/07/07 18:19:59 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_trash
{
	int				count;
	int				digits;
	int				i;
	char			result;
	int				n;
	int				fd;
}			*		t_trash;

typedef struct		s_pad_meta
{
	int				pad_mode;
	int				padding;
	int				prec;
}			*		t_pad_meta;

int					ft_printf(const char *str, ...);
int					ft_print_pre_padding(int fd, t_pad_meta pad, int count);
int					ft_print_post_padding(int fd, t_pad_meta pad, int count);
int					ft_get_digit_count_signed(long long n, int b, int p);

int					ft_max(int a, int b);
int					ft_check_negative(int nb, int fd);
int					ft_strnlen(char *str, int n);
unsigned long long	ft_pow(int base, int exp);

int					ft_get_digit_count(unsigned long long n, int b, int p);
int					ft_potstir_fd(char *stir, int fd, t_pad_meta pad);
int					ft_putchr_fd(char c, int fd, t_pad_meta pad);
int					ft_putunsigned_fd(unsigned int n, int fd, t_pad_meta pad);

int					ft_putint_fd(int n, int fd, t_pad_meta pad);
int					ft_putptr_fd(unsigned long long n, int fd, t_pad_meta pad);
int					ft_puthex_fd(unsigned long long n, int fd, t_pad_meta pad);
int					ft_putuhex_fd(unsigned long long n, int fd, t_pad_meta pad);

int					ft_get_pad_mode(const char **str);
int					ft_get_padding(const char **str);
int					ft_get_prec(const char **str, int prec);
void				ft_get_pad(const char **s, t_pad_meta m, va_list *a);

#endif

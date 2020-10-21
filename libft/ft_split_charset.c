/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:55:56 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 19:48:20 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_charset;

static int	ft_is_in_charset(char c)
{
	int i;

	i = 0;
	while (g_charset[i])
	{
		if (g_charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_count_tokens(const char *str)
{
	int in_token;
	int token_count;

	in_token = 0;
	token_count = 0;
	while (*str)
	{
		if (ft_is_in_charset(*str))
		{
			in_token = 0;
		}
		else
		{
			if (!in_token)
			{
				token_count++;
			}
			in_token = 1;
		}
		str++;
	}
	return (token_count);
}

char		*ft_strdup_to_delim(const char *str)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	i = 0;
	while (str[len] && !ft_is_in_charset(str[len]))
		len++;
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i] && !ft_is_in_charset(str[i]))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int			ft_split_helper(const char *str, char **tokens,
							int is_in_token, int *j)
{
	if (!is_in_token)
	{
		tokens[*j] = ft_strdup_to_delim(str);
		if (tokens[*j] == NULL)
		{
			return (0);
		}
		(*j)++;
	}
	return (1);
}

char		**ft_split_charset(const char *str, char *charset)
{
	int		i;
	int		j;
	int		is_in_token;
	char	**tokens;

	g_charset = charset;
	i = -1;
	j = 0;
	is_in_token = 0;
	tokens = (char **)malloc(sizeof(char *) * (ft_count_tokens(str) + 1));
	if (tokens == NULL)
		return (0);
	while (str[++i])
		if (ft_is_in_charset(str[i]))
			is_in_token = 0;
		else
		{
			if (!ft_split_helper(str + i, tokens, is_in_token, &j))
				return (0);
			is_in_token = 1;
		}
	tokens[ft_count_tokens(str)] = 0;
	return (tokens);
}

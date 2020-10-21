/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:52:57 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 20:52:05 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	if (s == NULL)
		return ((char*)NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = len < ft_strlen(s) - start ? len : ft_strlen(s) - start;
	if ((ret = (char*)malloc((len + 1) * sizeof(*ret))) == NULL)
		return (NULL);
	ft_memcpy(ret, &s[start], size + 1);
	ret[size] = 0;
	return (ret);
}

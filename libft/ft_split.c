/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:30:39 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 19:36:57 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char charset[2];

	if (!s)
		return (NULL);
	charset[0] = c;
	charset[1] = 0;
	return (ft_split_charset(s, charset));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:42:52 by agoodwin          #+#    #+#             */
/*   Updated: 2019/12/11 19:45:38 by agoodwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *new;

	if (!lst || !f || !(head = malloc(sizeof(t_list))))
		return (NULL);
	head->content = f(lst->content);
	new = head;
	while (lst->next)
	{
		if (!(new->next = malloc(sizeof(t_list))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = new->next;
		new->content = f(lst->content);
		lst = lst->next;
	}
	return (head);
}

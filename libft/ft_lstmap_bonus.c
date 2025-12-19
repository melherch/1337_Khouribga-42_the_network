/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:56:47 by mel-herc          #+#    #+#             */
/*   Updated: 2025/11/07 12:16:16 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	if (!new)
		return (NULL);
	node = new;
	lst = lst -> next;
	while (lst != NULL)
	{
		node -> next = ft_lstnew(f(lst -> content));
		if (!(node -> next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		else
		{
			lst = lst -> next;
			node = node -> next;
		}
	}
	return (new);
}

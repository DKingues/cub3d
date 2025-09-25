/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:15:52 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 14:40:33 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*cont;
	void	*fail;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		fail = f(lst->content);
		cont = ft_lstnew(fail);
		if (!cont)
		{
			del(fail);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, cont);
		lst = lst->next;
	}
	return (list);
}

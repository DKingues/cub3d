/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:23:23 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 15:10:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*elem;

	elem = ft_calloc (sizeof(t_list), 1);
	if (!elem)
		return (NULL);
	elem->content = cont;
	elem->next = (NULL);
	return (elem);
}
/*int main()
{
	t_list *node1 = ft_lstnew("hello");
	t_list *node2 = ft_lstnew("world");
	t_list *node3 = ft_lstnew("hey");
	t_list *node4 = ft_lstnew("ya");
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	while(node1)
	{
		printf("%s -> ", (char *)node1->content);
		node1 = node1->next;
	}
	return (0);
}*/
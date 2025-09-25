/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:36 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 15:10:25 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
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
	t_list *test = ft_lstlast(node1);
	printf("%s\n", (char *)test->content);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 15:10:00 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		var;

	temp = lst;
	var = 0;
	while (temp)
	{
		temp = temp->next;
		var++;
	}
	return (var);
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
	printf("%d\n", ft_lstsize(node1));
}*/
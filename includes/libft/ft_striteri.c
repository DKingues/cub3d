/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:28:25 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 17:54:47 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	var;
	size_t			siz;

	var = 0;
	siz = ft_strlen(s);
	if (!s || !f)
		return ;
	while (var < siz)
	{
		f(var, &s[var]);
		var++;
	}
	return ;
}

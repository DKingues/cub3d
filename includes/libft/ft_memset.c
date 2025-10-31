/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:47:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/10/28 13:01:20 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*int main(void)
{
    char str[50] = "Hello, World!";
    printf("Before ft_memset: %s\n", str);
    ft_memset(str, '*', 20);
    printf("After ft_memset:  %s\n", str);
    memset(str, '*', 20);
    printf("After memset:     %s\n", str);
}*/
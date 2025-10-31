/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:48:25 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/10/28 15:35:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*int main(void)
{
    char str[13] = "Hello, World!";
    printf("Before bzero: %s\n", str);
    ft_bzero(str, 20);
    printf("After ft_bzero:  %s\n", str);
	bzero(str, 20);
    printf("After bzero:  %s\n", str);
}*/
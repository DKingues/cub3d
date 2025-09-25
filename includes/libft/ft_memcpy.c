/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:13:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 17:52:20 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    char src[] = "Hello, World!";
    char dest[50] = "Hello, World!";
    ft_memcpy(dest, src, strlen(src) + 1);
    printf("ft_Source: %s\n", src);
    printf("ft_Destination: %s\n", dest);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:45:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 18:58:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*src_temp;
	char		*dest_temp;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	src_temp = (char *) src;
	dest_temp = (char *) dest;
	if (src_temp < dest_temp)
	{
		while (n-- > 0)
		{
			dest_temp[n] = src_temp[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	return (dest);
}

/*int main(void)
{
    char src[] = "Hello, World!";
    char dest[50];
	ft_memmove(dest, src, strlen(src) + 1);
    printf("ft_Source: %s\n", src);
    printf("ft_Destination: %s\n", dest);
}*/
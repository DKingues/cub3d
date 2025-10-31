/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:16:15 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 15:57:28 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	i = 0;
	while ((src[i] != '\0') && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int main()
{
	char dest[50]= "1234ww567890";
	char *src = "ww1234567890";
	size_t size = sizeof(dest);
	
	char dest2[50]= "1234ww567890";
	char *src2 = "ww1234567890";
	size_t size2 = sizeof(dest);
	
	printf("ft_strlcat: %zu\n", ft_strlcat(dest, src, size));
	printf("strlcat:    %zu\n", strlcat(dest2, src2, size2));
	return(0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:01:08 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 19:06:26 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dest, src, src_len +1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size -1);
		dest[size -1] = 0;
	}
	return (src_len);
}

/*int main()
{
	char src[]= "Helloasdf56s7fs,///, World";
	char dest[50];
	size_t size = 0;
	
	printf("ft_strlcpy: %zu\n", ft_strlcpy(dest, src, size));
	printf("strlcpy:    %zu\n", strlcpy(dest, src, size));
	return(0);
}*/
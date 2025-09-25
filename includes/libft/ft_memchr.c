/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:31 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 15:47:54 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	i = 0;
	str = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == cc)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

/*int main()
{
	const char str[] = "Hello World!";
   const char ch = 'H';
   char *ret;
   ret = memchr(str, ch, strlen(str));
   printf("ft_memchar: %s\n", ret);
}*/
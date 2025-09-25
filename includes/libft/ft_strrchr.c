/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:17:13 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 22:02:00 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)(s + i));
	}
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	if (s[0] == (char)c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

/*int main()
{
	char dest[70]= "abcdefghijklmfofpzxfcvfbnmzxfcvbnfmxcvbfzfxcfvbfnfq";
	int c = '\0';
	printf("%s\n", ft_strrchr(dest, c));
	printf("%s\n", strrchr(dest, c));
	return 10;
}*/
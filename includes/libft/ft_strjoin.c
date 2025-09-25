/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:39:57 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 18:37:11 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mal;

	mal = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!mal)
		return (NULL);
	if (mal)
	{
		ft_strcpy(mal, (char *)s1);
		ft_strcat(mal, (char *)s2);
	}
	return (mal);
}

/*int main()
{
	char *s1 = "atuamae";
	char *s2 = "emmboa";
	
	char *mal = ft_strjoin(s1, s2);
	printf("ft_strjoin: %s\n", mal);
	free(mal);
}*/
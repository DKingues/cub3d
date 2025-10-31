/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:28 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/01 22:18:20 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	while ((a < n) && (s1[a]) && (s2[a]))
	{
		if (s1[a] != s2[a])
		{
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		}
		a++;
	}
	if (a < n)
	{
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}

/*int	main()
{
	char s1[] = "a";
	char s2[] = "a";
	unsigned int n = 4;
	printf("%d\n",ft_strncmp(s1, s2, n));
	printf("%d\n",strncmp(s1, s2, n));
}*/
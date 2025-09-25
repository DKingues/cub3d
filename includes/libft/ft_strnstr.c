/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:48:13 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 16:16:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		a;
	size_t	b;

	b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] && b < len)
	{
		a = 0;
		if (big[b] == little[0])
		{
			while (big [b + a] == little[a] && little[a] && (b + a) < len)
				a++;
			if (little[a] == '\0')
				return ((char *)big + b);
		}
		b++;
	}
	return (NULL);
}

/*int main() 
{
    const char *texto = "Hello, world!";
    const char subtexto[] = "o";
	size_t len = 3;
    char *resultado = ft_strnstr(texto, subtexto, len);
    printf("ft_strnstr: %s \n", resultado);
}*/
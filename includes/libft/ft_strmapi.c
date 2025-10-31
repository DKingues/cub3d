/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:10 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 18:38:21 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mal;
	unsigned int	var;
	size_t			siz;

	siz = ft_strlen(s);
	var = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (var < siz)
	{
		mal[var] = f(var, s[var]);
		var++;
	}
	mal[var] = '\0';
	return (mal);
}

/*int main() 
{
    char *str = "Hello, World!";
    char *result = ft_strmapi(str, ft_strlen(str));
    if (result) 
	{
        printf("Original string: %s\n", str);
        printf("Modified string: %s\n", result);
        free(result);
    } else 
	{
        printf("Error: ft_strmapi returned NULL\n");
    }
}*/
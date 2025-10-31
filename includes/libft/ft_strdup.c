/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:17:14 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 18:28:53 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mal;
	int		a;

	a = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (s[a] != '\0')
	{
		mal[a] = s[a];
		a++;
	}
	mal[a] = '\0';
	return (mal);
}

/*int main(void)
{
    char    *src = "asdfh";
	char	*s1;
	s1 = ft_strdup(src);
    printf("Mydup       %s\n", s1);
	free(s1);
}*/
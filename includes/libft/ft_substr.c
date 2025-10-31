/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:45 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 18:36:29 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mal;
	size_t	var;

	var = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = (ft_strlen(s) - start);
	mal = ft_calloc((len + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (var < len)
	{
		mal[var] = s[start + var];
		var++;
	}
	mal[var] = '\0';
	return (mal);
}

/*int main()
{
	printf("ft_substr: %s\n", (ft_substr("Hello, world!", 5, 10)));
}*/
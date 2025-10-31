/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:18:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/07 15:49:41 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char s1, char const *set)
{
	while (*set != '\0')
	{
		if (s1 == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*temp;

	if (!s1 || !set)
		return ((char *) s1);
	i = 0;
	temp = (char *) s1;
	while (ft_check(*temp, set))
		temp++;
	i = ft_strlen(temp) - 1;
	while (ft_check(temp[i], set))
		i--;
	return (ft_substr(temp, 0, ++i));
}

/*int main(void)
{
    char    *src = "abcabccbaHh";
	char	*set = "abc";
	char	*s1;
	s1 = ft_strtrim(src, set);
    printf("Mydup       %s\n", s1);
	free(s1);
}*/
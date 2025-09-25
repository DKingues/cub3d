/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:15:07 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:17:25 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	var;
	int	check;

	var = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && var == 0)
		{
			var = 1;
			check++;
		}
		else if (*s == c)
			var = 0;
		s++;
	}
	return (check);
}

static char	*ft_write_word(const char *str, int start, int end)
{
	char	*mal;
	int		var;

	var = 0;
	mal = ft_calloc((end - start + 1), (sizeof(char)));
	if (!mal)
		return (NULL);
	while (start < end)
	{
		mal[var] = str[start];
		var++;
		start++;
	}
	mal[var] = 0;
	return (mal);
}

void	*ft_free(char **strs)
{
	int	var;

	var = 0;
	while (strs[var])
	{
		free(strs[var]);
		var++;
	}
	if(strs)
		free(strs);
	return (NULL);
}

static void	ft_init_var(size_t *var, int *var2, int *srch)
{
	*var = 0;
	*var2 = 0;
	*srch = -1;
}

#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**mal;
	size_t	var;
	int		var2;
	int		srch;

	ft_init_var(&var, &var2, &srch);
	mal = ft_calloc ((ft_count(s, c) + 1), sizeof(char *));
	if (!mal)
		return (NULL);
	while (var <= ft_strlen(s))
	{
		if (s[var] != c && srch < 0)
			srch = var;
		else if ((s[var] == c || var == ft_strlen(s)) && srch >= 0)
		{
			mal[var2] = ft_write_word(s, srch, var);
			if (!(mal[var2]))
				return (ft_free(mal));
			srch = -1;
			var2++;
		}
		var++;
	}
	return (mal);
}

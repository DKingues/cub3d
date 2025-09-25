/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:58:22 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			len;

	temp = malloc(nmemb * size);
	len = nmemb * size;
	if (size && (len / size) != nmemb)
		return (singleton_free(), printf("Malloc error.\n"), exit(1), NULL);
	if (temp == NULL)
		return (singleton_free(), printf("Malloc error.\n"), exit(1), NULL);
	if (nmemb == 0 || size == 0)
		return (singleton_free(), printf("Malloc error.\n"), exit(1), NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

/*int main()
{
	size_t a = 1;
	size_t b = 2;
	unsigned char *temp = NULL;
	ft_calloc(a, b);
	printf("ft_calloc: %s\n", temp);
	free(temp);
}*/
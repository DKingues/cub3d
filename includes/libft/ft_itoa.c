/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:17:03 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 18:22:52 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(long int n)
{
	long int	len;
	long int	nbr;

	len = 1;
	nbr = n;
	if (n < 0)
	{
		len ++;
		nbr = -nbr;
	}
	while (nbr / 10 != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*mal;
	long int	nbr;
	long int	len;

	nbr = n;
	len = ft_get_len(nbr);
	mal = ft_calloc((len + 1), sizeof(char));
	if (!mal)
		return (NULL);
	if (nbr < 0)
	{
		mal[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		mal[0] = '0';
	mal[len] = '\0';
	len--;
	while (len >= 0 && nbr > 0)
	{
		mal[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (mal);
}

/* int	main(void)
{
	char *test;

	test = ft_itoa(-2147483648);
	printf("%s\n", test);
	free(test);
	return (0);
} */
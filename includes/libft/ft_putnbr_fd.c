/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:30:56 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/04 19:44:19 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	bnb;

	bnb = n;
	if (fd)
	{
		if (bnb < 0)
		{
			ft_putchar_fd ('-', fd);
			bnb = -bnb;
		}
		if (bnb >= 10)
		{
			ft_putnbr_fd(bnb / 10, fd);
			bnb = bnb % 10;
		}
		if (bnb < 10)
			ft_putchar_fd(bnb + 48, fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:10:28 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 15:10:51 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	int_size(long time)
{
	int	i;

	i = 0;
	while (time > 0)
	{
		time /= 10;
		i++;
	}
	return (i);
}

int	timer(long start, int timer)
{
	struct timeval	curr;
	long			current;
	int				remaining;

	current = 0;
	remaining = 0;
	gettimeofday(&curr, NULL);
	current = curr.tv_sec;
	remaining = timer - (current - start) + game()->time.pause_time;
	game()->time.minutes = remaining / 60;
	game()->time.seconds = remaining % 60;
	return (0);
}

long	get_elapsed_sec(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL))
		return (0);
	return (current.tv_sec - game()->time.level_start);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (long)1e3 + (tv.tv_usec / 1e3));
}

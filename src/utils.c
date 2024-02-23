/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:05:20 by ahans             #+#    #+#             */
/*   Updated: 2024/02/23 15:42:29 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_dead(t_philo *philo, useconds_t time)
{
	if (get_time() - time > philo->params->time_to_die)
	{
		ft_msg(philo, DEAD);
		return (1);
	}
	return (0);
}

void	ft_msg(t_philo *philo, char *msg)
{
	printf("%ld %d %s\n", get_time() - philo->params->start_time,
		philo->id, msg);
}

long int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_error(ERR_GTOD));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if (result > 2147483647 && sign == 1)
			return (ft_error(ARG_OVERFLOW));
	}
	return (sign * result);
}

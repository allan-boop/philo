/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:05:20 by ahans             #+#    #+#             */
/*   Updated: 2024/02/25 18:13:26 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_msg(t_philo *philo, char *msg)
{
	int	ret;

	msg = msg;
	ret = -1;
	pthread_mutex_lock(philo->params->dead);
	if (philo->params->is_dead == 0)
	{
		if (philo->own_time_to_die > get_time())
		{
			printf(MSG, get_time() - philo->params->start_time, philo->id, msg);
			ret = 0;
		}
		else
		{
			printf(MSG, get_time() - philo->params->start_time, philo->id, DIE);
			philo->params->is_dead = 1;
			pthread_mutex_unlock(philo->fork);
			pthread_mutex_unlock(philo->l_fork);
		}
		pthread_mutex_unlock(philo->params->dead);
		return (ret);
	}
	pthread_mutex_unlock(philo->params->dead);
	return (ret);
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

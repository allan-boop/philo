/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:05:20 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 16:21:42 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_msg(t_philo *philo, char *msg, int should_die, int i)
{
	int	ret;

	ret = -1;
	if (pthread_mutex_lock(philo->params->dead) != 0)
		return (ret);
	if (philo->own_time_to_die >= get_time() && philo->params->is_dead == 0
		&& should_die == 0)
		ret = prr(philo, msg);
	else
	{
		if (philo->params->is_dead == 0)
			printf(MSG, get_time() - philo->params->start_time, philo->id, DIE);
		philo->params->is_dead = 1;
		if (i == 0)
			pthread_mutex_unlock(philo->fork);
		else if (i == 1)
			pthread_mutex_unlock(philo->l_fork);
		else if (i == 3)
			even_take_fork(philo, 0);
		else if (i == 4)
			odd_take_fork(philo, 0);
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

int	odd_take_fork(t_philo *philo, int i)
{
	if (i == 1)
	{
		if (pthread_mutex_lock(philo->fork) != 0)
			return (-1);
		if (ft_msg(philo, FORK, 0, 0) == -1)
			return (-1);
		if (pthread_mutex_lock(philo->l_fork) != 0)
			return (-1);
		if (ft_msg(philo, FORK, 0, 4) == -1)
			return (-1);
	}
	else
	{
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(philo->l_fork);
		return (0);
	}
	return (0);
}

int	even_take_fork(t_philo *philo, int i)
{
	if (i == 1)
	{
		if (pthread_mutex_lock(philo->l_fork) != 0)
			return (-1);
		if (ft_msg(philo, FORK, 0, 1) == -1)
			return (-1);
		if (pthread_mutex_lock(philo->fork) != 0)
			return (-1);
		if (ft_msg(philo, FORK, 0, 3) == -1)
			return (-1);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->fork);
		return (0);
	}
	return (0);
}

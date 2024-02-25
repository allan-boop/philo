/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:04:41 by ahans             #+#    #+#             */
/*   Updated: 2024/02/25 17:55:30 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_get_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork) == -1)
		return (ft_error(ERR_MUTEX));
	if (ft_msg(philo, FORK) == -1)
		return (-1);
	if (pthread_mutex_lock(philo->l_fork) == -1)
		return (ft_error(ERR_MUTEX));
	if (ft_msg(philo, FORK) == -1)
		return (-1);
	return (0);
}

void	ft_set_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	ft_eat(t_philo *philo)
{
	if (ft_msg(philo, EAT) == -1)
		return (-1);
	philo->meal_count--;
	if (philo->own_time_to_die - philo->params->time_to_eat / 1000 < get_time())
		usleep(philo->own_time_to_die - get_time());
	else
		usleep(philo->params->time_to_eat);
	philo->own_time_to_die = philo->params->time_to_die + get_time();
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_msg(philo, SLEEP) == -1)
		return (-1);
	if (philo->own_time_to_die - philo->params->time_to_sleep
		/ 1000 < get_time())
		usleep(philo->own_time_to_die - get_time());
	else
		usleep(philo->params->time_to_sleep);
	return (0);
}

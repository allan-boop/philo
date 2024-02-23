/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:04:41 by ahans             #+#    #+#             */
/*   Updated: 2024/02/23 12:06:06 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	ft_msg(philo, FORK);
	pthread_mutex_lock(philo->l_fork);
	ft_msg(philo, FORK);
}

void	ft_set_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_eat(t_philo *philo)
{
	ft_msg(philo, EAT);
	philo->meal_count--;
	usleep(philo->params->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	ft_msg(philo, SLEEP);
	usleep(philo->params->time_to_sleep);
}

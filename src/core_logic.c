/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/21 20:20:29 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	ft_msg(philo, FORK);
	pthread_mutex_lock(philo->l_fork);
	ft_msg(philo, FORK);
	ft_msg(philo, EAT);
	philo->meal_count--;
	usleep(philo->params->time_to_eat);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_msg(philo, SLEEP);
	usleep(philo->params->time_to_sleep);
	ft_msg(philo, THINK);
	return (0);
}

void	routine(t_philo *philo)
{
	while (philo->meal_count > 0)
		eat(philo);
}

void	*philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		routine(philo);
	else
	{
		usleep(10);
		routine(philo);
	}
	return (NULL);
}
int	execute_core_logic(t_philo *philos)
{
	int	philo_nb;

	philo_nb = philos[0].params->nb_of_philo;
	philos[0].params->start_time = get_time();
	if (philos[0].params->start_time == -1)
		return (-1);
	philo_nb = philos[0].params->nb_of_philo;
	while (philo_nb--)
	{
		if (pthread_create(&philos[philo_nb].thread, NULL,
				(void *)philo_life, &philos[philo_nb]) != 0)
			return (ft_error(ERR_PTHREAD));
		ft_usleep(1);
	}
	philo_nb = philos[0].params->nb_of_philo;
	while (philo_nb--)
		pthread_join(philos[philo_nb].thread, NULL);
	usleep(10000000);
	return (0);
}

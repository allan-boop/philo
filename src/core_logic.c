/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 15:59:25 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_is_dead(t_philo *philo)
{
	int	f;

	f = 1;
	pthread_mutex_lock(philo->params->dead);
	if (philo->params->is_dead == 0)
		f = 0;
	pthread_mutex_unlock(philo->params->dead);
	return (f);
}

static int	routine(t_philo *philo)
{
	while (philo->meal_count > 0 && check_is_dead(philo) == 0)
	{
		if (ft_get_fork(philo) == -1)
			return (-1);
		if (ft_eat(philo) == -1)
			return (-1);
		ft_set_down_fork(philo);
		if (ft_sleep(philo) == -1)
			return (-1);
		pthread_mutex_lock(philo->params->dead);
		if (philo->params->is_dead == 0)
		{
			pthread_mutex_unlock(philo->params->dead);
			if (ft_msg(philo, THINK, 0, 6) == -1)
				return (-1);
		}
		else
			pthread_mutex_unlock(philo->params->dead);
	}
	return (0);
}

static void	philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		routine(philo);
	else
	{
		usleep(philo->params->time_to_eat / 2);
		routine(philo);
	}
}

int	execute_core_logic(t_philo *philos)
{
	int	i;

	i = 0;
	philos[0].params->start_time = get_time();
	if (philos[0].params->start_time == -1)
		return (-1);
	while (i < philos[0].params->nb_of_philo)
	{
		philos[i].own_time_to_die = philos[0].params->time_to_die
			+ get_time();
		if (pthread_create(&philos[i].thread, NULL,
				(void *)philo_life, &philos[i]) != 0)
		{
			i--;
			while (i >= 0)
			{
				pthread_join(philos[i--].thread, NULL);
			}
			return (ft_error(ERR_PTHREAD));
		}
		i++;
	}
	while (i--)
		pthread_join(philos[i].thread, NULL);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 13:13:15 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	routine(t_philo *philo)
{
	while (philo->meal_count > 0 && philo->params->is_dead == 0)
	{
		if (ft_get_fork(philo) == -1)
			return (-1);
		if (ft_eat(philo) == -1)
			return (-1);
		ft_set_down_fork(philo);
		if (ft_sleep(philo) == -1)
			return (-1);
		if (philo->params->is_dead == 0)
		{
			if (ft_msg(philo, THINK, 0) == -1)
				return (-1);
		}
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
	int	philo_nb;
	int	i;

	i = 0;
	philo_nb = philos[0].params->nb_of_philo;
	philos[0].params->start_time = get_time();
	if (philos[0].params->start_time == -1)
		return (-1);
	philo_nb = philos[0].params->nb_of_philo;
	while (i < philo_nb)
	{
		philos[i].own_time_to_die = philos[0].params->time_to_die
			+ get_time();
		if (pthread_create(&philos[i].thread, NULL,
				(void *)philo_life, &philos[i]) != 0)
		{
			i--;
			while (i >= 0)
			{
				pthread_join(philos[i].thread, NULL);
				i--;
			}
			return (ft_error(ERR_PTHREAD));
		}
		i++;
	}
	while (i--)
		pthread_join(philos[i].thread, NULL);
	return (0);
}

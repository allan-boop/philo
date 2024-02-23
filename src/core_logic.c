/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/23 15:40:02 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	routine(t_philo *philo)
{
	while (philo->meal_count > 0)
	{
		ft_get_fork(philo);
		ft_eat(philo);
		ft_set_down_fork(philo);
		ft_sleep(philo);
		ft_msg(philo, THINK);
	}
}

static void	*philo_life(t_philo *philo)
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
	}
	philo_nb = philos[0].params->nb_of_philo;
	while (philo_nb--)
		pthread_join(philos[philo_nb].thread, NULL);
	usleep(1000000);
	return (0);
}

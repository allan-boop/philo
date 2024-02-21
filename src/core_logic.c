/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/21 12:55:22 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*
int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->l_fork);
	usleep(200);
	printf("%d %d is eating\n", get_time(), philo->id);
	philo->time_of_eat--;
	pthread_mutex_unlock(philo->fork);
	return (0);
}

void	*philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		printf("%d %d has taken a fork\n", get_time(), philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%d %d has taken a fork\n", get_time(), philo->id);
	}
	else
		usleep(20);
	while (philo->time_of_eat > 0)
		eat(philo);
	return (NULL);
}
*/
int	execute_core_logic(t_philo *philos)
{
	philos = philos;
/*
	int	philo_nb;

	philo_nb = params.nb_of_philo;
	params.start_time = get_time();
	if (params.start_time == -1)
		return (-1);
	while (philo_nb--)
	{
	}
	philo_nb = params.nb_of_philo;
	while (philo_nb--)
	{
		if (pthread_create(&params.philos[philo_nb].thread, NULL,
				(void *)philo_life, &params.philos[philo_nb]) != 0)
			return (ft_error(ERR_PTHREAD));
		pthread_join(params.philos[philo_nb].thread, NULL);
	}
*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:32:56 by ahans             #+#    #+#             */
/*   Updated: 2024/02/19 17:08:20 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	philo = philo;
	//philo->time_of_eat--;
	return (0);
}

void	*philo_life(void *philo)
{
	//while (philo->time_of_eat > 0)
	eat(philo);
	return (NULL);
}

int	execute_core_logic(t_params params)
{
	int	philo_nb;

	philo_nb = params.nb_of_philo;
	params.start_time = get_time();
	if (params.start_time == -1)
		return (-1);
	while (philo_nb--)
	{
		if (pthread_create(&params.philos[philo_nb].thread, NULL, \
		(void *)philo_life, &params.philos[philo_nb]) != 0)
			return (ft_error(ERR_PTHREAD));
	}
	return (0);
}

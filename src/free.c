/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:54:01 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 13:22:18 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_tab(t_philo **philos, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy((*philos)[j].fork);
		free((*philos)[j].fork);
		j++;
	}
}

void	free_all(t_philo *philos)
{
	free_tab(&philos, philos[0].params->nb_of_philo);
	pthread_mutex_destroy(philos[0].params->dead);
	free(philos[0].params->dead);
	free(philos[0].params);
	free((philos));
}

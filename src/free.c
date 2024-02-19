/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:54:01 by ahans             #+#    #+#             */
/*   Updated: 2024/02/19 17:26:38 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_tab(t_params params, int i)
{
	int	j;

	params = params;
	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(params.philos[j].fork);
		free(params.philos[j].fork);
		j++;
	}
}

void	free_all(t_params params)
{
	free_tab(params, params.nb_of_philo);
	free(params.philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:39:08 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 14:07:38 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;

	philos = NULL;
	if (set_parsing(&philos, ac, av) == -1)
		return (-1);
	if (philos[0].params->nb_of_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(philos[0].params->time_to_die * 1000);
		printf("%d 1 died\n", philos[0].params->time_to_die);
	}
	else
		execute_core_logic(philos);
	free_all(philos);
}

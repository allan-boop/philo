/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:39:08 by ahans             #+#    #+#             */
/*   Updated: 2024/02/21 13:44:14 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;

	philos = NULL;
	if (set_parsing(&philos, ac, av) == -1)
		return (-1);
	execute_core_logic(philos);
	free_all(philos);
}

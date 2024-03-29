/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:49:15 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 12:52:55 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *msg)
{
	printf("%s", msg);
	return (-1);
}

int	error_free_params(t_params *params, char *msg)
{
	free(params);
	return (ft_error(msg));
}

int	ft_error_philos(t_params *params, char *msg)
{
	pthread_mutex_destroy(params->dead);
	free(params->dead);
	free(params);
	return (ft_error(msg));
}

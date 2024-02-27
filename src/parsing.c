/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:45:44 by ahans             #+#    #+#             */
/*   Updated: 2024/02/27 17:10:17 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_params(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ft_error(DIGIT_ERR));
			j++;
		}
		i++;
	}
	return (0);
}

static int	free_call(t_philo *philos, int i, t_params *params)
{
	free_tab(&philos, i);
	free(philos);
	free(params->dead);
	free(params);
	return (ft_error(MALLOC_ERR));
}

static int	init_philos(t_philo **philos, t_params *params)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * (*params).nb_of_philo);
	if (!*philos)
		return (ft_error_philos(params, MALLOC_ERR));
	while (i < params->nb_of_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meal_count = (*params).nb_of_t_each_philo_must_eat;
		(*philos)[i].own_time_to_die = (*params).time_to_die;
		(*philos)[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!(*philos)[i].fork)
			return (free_call(*philos, i, params));
		pthread_mutex_init((*philos)[i].fork, NULL);
		(*philos)[i].params = params;
		if (i > 0)
			(*philos)[i].l_fork = (*philos)[i - 1].fork;
		i++;
	}
	(*philos)[0].l_fork = (*philos)[params->nb_of_philo - 1].fork;
	return (0);
}

static int	init_params(t_philo **philos, int ac, char **av)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return (ft_error(MALLOC_ERR));
	params->nb_of_philo = ft_atol(av[1]);
	if (params->nb_of_philo == 0)
		return (error_free_params(params, NO_PHILO));
	params->time_to_die = ft_atol(av[2]);
	params->time_to_eat = ft_atol(av[3]) * 1000;
	params->time_to_sleep = ft_atol(av[4]) * 1000;
	params->dead = malloc(sizeof(pthread_mutex_t));
	if (!params->dead)
		return (error_free_params(params, MALLOC_ERR));
	params->is_dead = 0;
	pthread_mutex_init(params->dead, NULL);
	if (ac == 6)
		params->nb_of_t_each_philo_must_eat = ft_atol(av[5]);
	else
		params->nb_of_t_each_philo_must_eat = INT_MAX;
	if (params->nb_of_philo == -1 || params->time_to_die == -1
		|| params->time_to_eat == -1 || params->time_to_sleep == -1
		|| (ac == 6 && params->nb_of_t_each_philo_must_eat == -1))
		return (-1);
	return (init_philos(philos, params));
}

int	set_parsing(t_philo **philos, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_error(ARG_ERR));
	if (check_params(ac, av) == -1)
		return (-1);
	return (init_params(philos, ac, av));
}

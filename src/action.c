/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:04:41 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 16:25:25 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_get_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (even_take_fork(philo, 1));
	else
		return (odd_take_fork(philo, 1));
}

void	ft_set_down_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		even_take_fork(philo, 2);
	else
		odd_take_fork(philo, 2);
}

int	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (ft_msg(philo, EAT, 0, 3) == -1)
			return (-1);
	}
	else
		if (ft_msg(philo, EAT, 0, 4) == -1)
			return (-1);
	philo->meal_count--;
	if (philo->own_time_to_die - philo->params->time_to_eat / 1000 < get_time())
	{
		usleep((philo->own_time_to_die - get_time()) * 1000);
		if (philo->id % 2 == 0)
			ft_msg(philo, DIE, 1, 3);
		else
			ft_msg(philo, DIE, 1, 4);
		return (-1);
	}
	else
		usleep(philo->params->time_to_eat);
	philo->own_time_to_die = philo->params->time_to_die + get_time();
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	int	should_die;

	should_die = 0;
	if (ft_msg(philo, SLEEP, should_die, 6) == -1)
		return (-1);
	if (philo->own_time_to_die - philo->params->time_to_sleep
		/ 1000 < get_time())
	{
		usleep((philo->own_time_to_die - get_time()) * 1000);
		should_die = 1;
		ft_msg(philo, DIE, should_die, 6);
		return (-1);
	}
	else
		usleep(philo->params->time_to_sleep);
	return (0);
}

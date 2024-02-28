/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:42 by ahans             #+#    #+#             */
/*   Updated: 2024/02/28 16:19:33 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	prr(t_philo *philo, char *msg)
{
	printf(MSG, get_time() - philo->params->start_time, philo->id, msg);
	return (0);
}

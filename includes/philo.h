/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:31 by ahans             #+#    #+#             */
/*   Updated: 2024/02/18 18:22:52 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

# define MALLOC_ERR "Malloc error\n"
# define ARG_ERR "Wrong number of arguments\n"
# define ARG_OVERFLOW "Argument overflow\n"
# define DIGIT_ERR "Arguments must be a positive digits\n"

typedef struct s_philo
{
	int				id;
	int				own_time_to_die; //temps avant la mort
	int				own_time_to_eat; //temps avant fin de repas
	pthread_mutex_t	*fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct s_params
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	int		start_time;
	t_philo	*philos;
}				t_params;

int		set_parsing(t_params *params, int ac, char **av);
int		ft_error(char *msg);
long	ft_atol(const char *nptr);
void	execute_core_logic(t_params params);
int		get_time(void);
void	free_all(t_params params);
void	free_tab(t_params params, int i);

#endif

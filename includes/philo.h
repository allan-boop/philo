/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:31 by ahans             #+#    #+#             */
/*   Updated: 2024/02/23 15:38:44 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define MALLOC_ERR "Malloc error\n"
# define ARG_ERR "Wrong number of arguments\n"
# define ARG_OVERFLOW "Argument overflow\n"
# define DIGIT_ERR "Arguments must be a positive digits\n"
# define ERR_GTOD "Error in gettimeofday\n"
# define ERR_PTHREAD "Error in pthread_create\n"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIE "died\n"

typedef struct s_params
{
	int			nb_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_of_t_each_philo_must_eat;
	long int	start_time;
	int			dead;
}				t_params;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meal_count; //nombre de repas
	int				own_time_to_die; //temps avant la mort
	int				own_time_to_eat; //temps avant fin de repas
	pthread_mutex_t	*fork;
	pthread_mutex_t	*l_fork;
	t_params		*params;
}				t_philo;

int			set_parsing(t_philo **philos, int ac, char **av);
int			ft_error(char *msg);
long		ft_atol(const char *nptr);
int			execute_core_logic(t_philo *philos);
long int	get_time(void);
void		free_all(t_philo *philos);
void		free_tab(t_philo **philos, int i);
void		ft_msg(t_philo *philo, char *msg);
void		ft_get_fork(t_philo *philo);
void		ft_set_down_fork(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:00:50 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:29 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

size_t	get_ms_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_args(char **av, t_args *args)
{
	int	i;
	pthread_mutex_t *fork = malloc(sizeof(pthread_mutex_t) * _atoi(av[1]));
	pthread_mutex_t *eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_t *print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_t *last_m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(eat, NULL);
	pthread_mutex_init(print, NULL);
	pthread_mutex_init(last_m, NULL);
	i = -1;
	while (++i < _atoi(av[1]))
	{
		pthread_mutex_init(&fork[i], NULL);
	}
	i = -1;
	while (++i < _atoi(av[1]))
	{
		(args + i)->n_philo = _atoi(av[1]);
		(args + i)->tt_die = _atoi(av[2]);
		(args + i)->tt_eat = _atoi(av[3]);
		(args + i)->tt_sleep = _atoi(av[4]);
		(args + i)->need_eat = _atoi(av[5]);
		(args + i)->philo_id = i;
		(args + i)->start = get_ms_time();
		(args + i)->last_meal = get_ms_time();
		(args + i)->m_fork = fork;
		(args + i)->m_eat = eat;
		(args + i)->m_print = print;
		(args + i)->m_last_meal = last_m;
	}
}

void	is_dead(t_args *args)
{
	while (1)
	{
		int i = 0;
		while (i < args->n_philo)
		{
			pthread_mutex_lock(args->m_last_meal);
			if (get_ms_time() - args[i].last_meal > (size_t)args->tt_die)
			{
				pthread_mutex_lock(args->m_print);
				printf("%5zu ms %zu died\n", get_ms_time() - args->start, args[i].philo_id + 1);
				return ;
			}
			pthread_mutex_unlock(args->m_last_meal);
			i++;
		}
	}
}

void	_usleep(size_t time_activite)
{
	size_t	cur;

	cur = get_ms_time();
	while (get_ms_time() - cur < time_activite)
		usleep(100);
}


////// mutex of print....
////// return from is dead if need_eat of all philos is equal to 0.
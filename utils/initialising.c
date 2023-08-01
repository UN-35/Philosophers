/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:00:50 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/02 00:46:59 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

size_t	_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_mutex	init_mutex(char **av)
{
	t_mutex	mutex;

	mutex.fork = malloc(sizeof(pthread_mutex_t) * _atoi(av[1]));
	mutex.eat = malloc(sizeof(pthread_mutex_t));
	mutex.print = malloc(sizeof(pthread_mutex_t));
	mutex.last_m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex.eat, NULL);
	pthread_mutex_init(mutex.print, NULL);
	pthread_mutex_init(mutex.last_m, NULL);
	return (mutex);
}

void	init_args(char **av, t_args *args)
{
	int		i;
	t_mutex	mutex;

	mutex = init_mutex(av);
	i = -1;
	while (++i < _atoi(av[1]))
		pthread_mutex_init(&mutex.fork[i], NULL);
	i = -1;
	while (++i < _atoi(av[1]))
	{
		(args + i)->n_philo = _atoi(av[1]);
		(args + i)->tt_die = _atoi(av[2]);
		(args + i)->tt_eat = _atoi(av[3]);
		(args + i)->tt_sleep = _atoi(av[4]);
		(args + i)->need_eat = _atoi(av[5]);
		(args + i)->p_id = i;
		(args + i)->s = _time();
		(args + i)->last_meal = _time();
		(args + i)->m_fork = mutex.fork;
		(args + i)->m_eat = mutex.eat;
		(args + i)->m_print = mutex.print;
		(args + i)->m_last_meal = mutex.last_m;
	}
}

void	_usleep(size_t time_activite)
{
	size_t	cur;

	cur = _time();
	while (_time() - cur < time_activite)
		usleep(100);
}

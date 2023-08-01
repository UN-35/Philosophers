/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:26:03 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/02 00:37:38 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	_print(char *msg, t_args *args, size_t id)
{
	pthread_mutex_lock(args->m_print);
	printf("%5zu ms %zu %s\n", _time() - args->s, id + 1, msg);
	pthread_mutex_unlock(args->m_print);
}

int	_check_need_eat(int *n)
{
	if (*n != 0)
		n--;
	return (*n);
}

void	*_routine(void *arg)
{
	t_args	*args;

	args = (t_args *)arg;
	while (1)
	{
		pthread_mutex_lock(args->m_fork + args->p_id);
		_print("has taken a fork", args, args->p_id);
		pthread_mutex_lock(args->m_fork + ((args->p_id + 1) % args->n_philo));
		_print("has taken a fork", args, args->p_id);
		_print("is eating", args, args->p_id);
		pthread_mutex_lock(args->m_last_meal);
		args->last_meal = _time();
		pthread_mutex_unlock(args->m_last_meal);
		_usleep(args->tt_eat);
		pthread_mutex_unlock(args->m_fork + ((args->p_id + 1) % args->n_philo));
		pthread_mutex_unlock(args->m_fork + args->p_id);
		pthread_mutex_lock(args->m_eat);
		if (args->need_eat != 0)
			args->need_eat--;
		pthread_mutex_unlock(args->m_eat);
		_print("is sleeping", args, args->p_id);
		_usleep(args->tt_sleep);
		_print("is thinking", args, args->p_id);
	}
	return (NULL);
}

void	th_create(t_args *args)
{
	int			i;
	pthread_t	*th;

	th = malloc(sizeof(pthread_t) * (args->n_philo));
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_create(&th[i], NULL, _routine, args + i))
			return ;
		usleep(100);
		i++;
	}
	free(th);
}

int	main(int ac, char **av)
{
	t_args	*args;

	if (_valid_args(ac, av))
		return (1);
	args = malloc (sizeof(t_args) * _atoi(av[1]));
	pthread_mutex_init(&(args->test_m), NULL);
	init_args(av, args);
	th_create(args);
	is_dead(args, 0);
	return (0);
}

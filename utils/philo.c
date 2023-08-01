/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:26:03 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/01 18:19:41 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	_print(char *msg, t_args *args, size_t id)
{
	pthread_mutex_lock(args->m_print);
	printf("%5zu ms %zu %s\n",get_ms_time() - args->start, id + 1, msg);
	pthread_mutex_unlock(args->m_print);
}

void	*_routine(void *arg)
{
	t_args *args = (t_args*) arg;
	size_t id = args->philo_id;
	while (1)
	{

		pthread_mutex_lock(args->m_fork + id);
		_print("has taken a fork", args, id);
		pthread_mutex_lock(args->m_fork + ((id + 1) % args->n_philo));
		_print("has taken a fork", args, id);
		_print("is eating", args, id);
		pthread_mutex_lock(args->m_last_meal);
		args->last_meal = get_ms_time();
		pthread_mutex_unlock(args->m_last_meal);
		_usleep(args->tt_eat);
		pthread_mutex_unlock(args->m_fork + ((id + 1) % args->n_philo));
		pthread_mutex_unlock(args->m_fork + id);
		pthread_mutex_lock(args->m_eat);
		if (args->need_eat != 0)
			args->need_eat--;
		pthread_mutex_unlock(args->m_eat);
		_print("is sleeping", args, id);
		_usleep(args->tt_sleep);
		_print("is thinking", args, id);
	}
	return NULL;
}

void	th_create(t_args *args)
{
	pthread_t *th;
	int i;
	th = malloc(sizeof(pthread_t) * (args->n_philo));
	i = 0;
	while(i < args->n_philo)
	{
		if (pthread_create(&th[i], NULL, _routine, args + i))
			return ;
		usleep(100);
		if (pthread_detach(th[i]))
			return ;
		i++;
	}
}

int main(int ac, char **av)
{
	if (_valid_args(ac, av))
		return (1);
	t_args *args = malloc (sizeof(t_args) * _atoi(av[1]));
	init_args(av, args);
	th_create(args);
	is_dead(args);
	return 0;
}







//  0x7ff8b6c02a80
//  0x7ff8b6c02ac0 +++
//  0x7ff8b6c02ac0 +++
//  0x7ff8b6c02b00 -------
//  0x7ff8b6c02b00 -----
//  0x7ff8b6c02b40 --
//  0x7ff8b6c02b40 --
//  0x7ff8b6c02a80
//  0x7ff8b6c02a80
//  0x7ff8b6c02ac0 ++
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:47:10 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/02 16:39:55 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	end_procces(t_args *a, int i)
{
	pthread_mutex_lock(a->m_print);
	printf("%5zu ms %zu died\n", _time() - a->s, a[i].p_id + 1);
	return (1);
}

int	is_dead(t_args *a, int i)
{
	while (1)
	{
		i = -1;
		while (++i < a->n_philo)
		{
			pthread_mutex_lock(a->m_last_meal);
			if (_time() - a[i].last_meal >= (size_t)a->tt_die)
				return (end_procces(a, i));
			pthread_mutex_unlock(a->m_last_meal);
		}
		i = -1;
		while (++i < a->n_philo)
		{
			pthread_mutex_lock(a->m_eat);
			if (a[i].need_eat != 0)
			{
				pthread_mutex_unlock(a->m_eat);
				break ;
			}
			else
				pthread_mutex_unlock(a->m_eat);
		}
		if (i == a->n_philo)
			return (0);
	}
}

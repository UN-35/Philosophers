/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:25:57 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/02 00:46:25 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_args
{
	int				n_philo;
	int				tt_eat;
	int				tt_die;
	int				tt_sleep;
	int				need_eat;
	int				save_eating;
	size_t			p_id;
	size_t			s;
	size_t			last_meal;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	test_m;
	pthread_mutex_t	*m_last_meal;
}	t_args;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*print;
	pthread_mutex_t	*last_m;
}	t_mutex;

int		_atoi(char *str);
int		_valid_args(int ac, char **args);
void	init_args(char **av, t_args *args);
size_t	_time(void);
void	_usleep(size_t time_activite);
int		is_dead(t_args *args, int i);

#endif

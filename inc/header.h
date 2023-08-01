/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:25:57 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/01 18:05:05 by yoelansa         ###   ########.fr       */
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
	size_t			philo_id;
	size_t			start;
	size_t			last_meal;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_last_meal;
}	t_args;

int		_atoi(char *str);
int		_valid_args(int ac, char **args);
void	init_args(char **av, t_args *args);
size_t	get_ms_time(void);
void	_usleep(size_t time_activite);
void	is_dead(t_args *args);

#endif

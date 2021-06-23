/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilosophers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushin <sushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:14:03 by sushin            #+#    #+#             */
/*   Updated: 2021/06/23 11:14:05 by sushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_philo
{
	pthread_t		tid;
	int				num;
	int				r_fork;
	int				l_fork;
	int				eat_cnt;
	struct s_rule	*rule;
	// struct s_mutex	*mutex;
	// struct timeval	start_tv;
	// struct timeval	life_tv;
}					t_philo;

typedef struct		s_rule
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}					t_rule;

int		ft_atoi(const char *str);
t_rule	*rule_structure(char **av);
t_philo	**philo_structure(t_rule *rules, char *av_1);
#endif


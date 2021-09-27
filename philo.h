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

enum states {
	eating = 1,
	sleeping,
	thinking
};

typedef struct		s_philo
{
	pthread_t		tid;
	pthread_t		monitor;
	int				num;
	int				r_fork;
	int				l_fork;
	int				eat_cnt;
	struct s_rule	*rule;
	struct s_mutex	*mutex;
}					t_philo;

typedef struct		s_rule
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_rule;

typedef struct		s_mutex
{
	pthread_mutex_t *fork_mutex;
}					t_mutex;

int		ft_atoi(const char *str);
t_rule	*rule_structure(char **av);
t_philo	**philo_structure(t_rule *rules, t_mutex *mutexs);
t_mutex	*mutex_structure(int philonum);
void	*philo_act(void *data);
void	*monitor_act(void *data);
void	th_detach(t_philo **philos, t_rule *rules);



//error_function
void	pthread_create_error_check(int thr_err_chk);

#endif

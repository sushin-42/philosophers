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

# define EAT 1
# define SLEEP 2
# define THINK 3
# define LFORK 4
# define RFORK 5
# define PLFORK 6
# define PRFORK 7
# define DIE 8


enum states {
	eating = 1,
	sleeping,
	thinking
};

typedef struct		s_philo
{
	pthread_t		tid;
	int				num;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				eat_cnt;
	struct s_rule	*rule;
	struct s_mutex	*mutex;
	struct timeval	start;
	struct timeval	eat_time;

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
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	writing_mutex;
}					t_mutex;

int		ft_atoi(const char *str);
t_rule	*rule_structure(char **av);
t_philo	**philo_structure(t_rule *rules, t_mutex *mutexs);
t_mutex	*mutex_structure(int philonum);
void	*philo_act(void *data);
void	putdown_fork(t_philo *philos);
void	take_fork(t_philo *philos);
void	act_eat(t_philo *philos);
void	writing(t_philo *philos, int state);
void	act_sleep(t_philo *philos);
void	div_usleep(long int time);
long int	timediff(struct timeval *start, struct timeval *end);
void	act_think(t_philo *philos);
void	monitor_philo(t_philo **philos);
void	eat_monitor(t_philo **philos);
void	die_monitor(t_philo **philos);
int	check_alive(t_philo **philos);




//error_function
void	pthread_create_error_check(int thr_err_chk);

#endif

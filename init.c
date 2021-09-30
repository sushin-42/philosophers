#include "philo.h"

t_philo	**philo_structure(t_rule *rules, t_mutex *mutexs)
{
	t_philo	**philos;
	int		i;
	int		thr_err_chk;

	philos = (t_philo **)malloc(sizeof(t_philo *) * rules->num);
	i = 0;
	gettimeofday(&(rules->start), NULL);
	while (i < rules->num)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->eat_cnt = 0;
		philos[i]->rule = rules;
		philos[i]->num = i;
		philos[i]->mutex = mutexs;
		philos[i]->r_fork = &(mutexs->fork_mutex[i]);
		philos[i]->l_fork = &(mutexs->fork_mutex[(i + 1) % rules->num]);
		thr_err_chk = pthread_create(&(philos[i]->tid), NULL, philo_act,
				(void *)philos[i]);
		pthread_create_error_check(thr_err_chk);
		pthread_detach(philos[i]->tid);
		usleep(100);
		i++;
	}
	return (philos);
}

t_rule	*rule_structure(char **av)
{
	t_rule	*rules;

	rules = (t_rule *)malloc(sizeof(t_rule));
	rules->num = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->die_check = 0;
	if (av[5])
		rules->must_eat = ft_atoi(av[5]);
	else
		rules->must_eat = -1;
	return (rules);
}

t_mutex	*mutex_structure(int philonum)
{
	int				i;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	writing_mutex;
	t_mutex			*main_mutex;

	main_mutex = (t_mutex *)malloc(sizeof(t_mutex));
	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philonum);
	i = 0;
	while (i < philonum)
	{
		pthread_mutex_init(&fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&writing_mutex, NULL);
	main_mutex->fork_mutex = fork_mutex;
	main_mutex->writing_mutex = writing_mutex;
	return (main_mutex);
}

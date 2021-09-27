#include "philo.h"

t_philo	**philo_structure(t_rule *rules, t_mutex *mutexs)
{
	t_philo	**philos;
	int		i;
	int		thr_err_chk;


	philos = (t_philo **)malloc(sizeof(t_philo *) * rules->num);
	i = -1;
	while (i++ < rules->num - 1)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		thr_err_chk = pthread_create(&(philos[i]->tid), NULL, philo_act, (void *)philos[i]);
		pthread_create_error_check(thr_err_chk);
		thr_err_chk = pthread_create(&(philos[i]->monitor), NULL, monitor_act, (void *)philos[i]);
		pthread_create_error_check(thr_err_chk);
		philos[i]->rule = rules;
		philos[i]->num = rules->num;
		philos[i]->mutex = mutexs;
	}
	return (philos);
}

void	*philo_act(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	return (NULL);
}

void	*monitor_act(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	return (NULL);
}

t_rule	*rule_structure(char **av)
{
	t_rule	*rules;

	rules = (t_rule *)malloc(sizeof(t_rule));
	rules->num = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		rules->must_eat = ft_atoi(av[5]);
	else
		rules->must_eat = 0;
	return (rules);
}

t_mutex	*mutex_structure(int philonum)
{
	int	i;
	pthread_mutex_t	*fork_mutex;
	t_mutex *main_mutex;

	main_mutex = (t_mutex *)malloc(sizeof(t_mutex));
	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philonum);
	i = 0;
	while (i < philonum)
	{
		pthread_mutex_init(&fork_mutex[i], NULL);
		i++;
	}
	main_mutex->fork_mutex = fork_mutex;
	return (main_mutex);
}

// void	th_detach(t_philo **philos, t_rule *rules)
// {
// 	int	i;

// 	i = 0;
// 	while(i < rules->num)
// 	{
// 		printf("detach %d\n", i);
// 		pthread_join(philos[i]->tid, NULL);
// 		i++;
// 	}
// }

int		main(int ac, char **av)
{
	t_philo	**philos;
	t_rule	*rules;
	t_mutex *mutexs;

	if (ac != 5 && ac != 6)
		return (printf("arguments error\n"));
	rules = rule_structure(av);
	mutexs = mutex_structure(rules->num);
	philos = philo_structure(rules, mutexs);

	// th_detach(philos, rules);
	return (0);
}

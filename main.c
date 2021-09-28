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
		philos[i]->num = i;
		philos[i]->mutex = mutexs;
	}
	return (philos);
}

void	*philo_act(void *data)
{
	t_philo	*philos;
	int i = 0;
	philos = (t_philo *)data;
	while(i < 5)
	{
		if (philos->num % 2 == 0)
		{
			pthread_mutex_lock(&(philos->mutex->fork_mutex[philos->num % philos->rule->num]));
			printf("%d has taken a %d left fork\n", philos->num, philos->num % philos->rule->num);
			pthread_mutex_lock(&(philos->mutex->fork_mutex[(philos->num + 1) % philos->rule->num]));
			printf("%d has taken a %d right fork\n", philos->num, (philos->num + 1) % philos->rule->num);

			pthread_mutex_unlock(&(philos->mutex->fork_mutex[philos->num % philos->rule->num]));
			printf("%d put down a left fork\n", philos->num);
			pthread_mutex_unlock(&(philos->mutex->fork_mutex[(philos->num + 1) % philos->rule->num]));
			printf("%d put down a right fork\n", philos->num);
			printf("%d sleeping\n", philos->num);

			usleep(philos->rule->time_to_sleep * 1000);
		}
		else if (philos->num % 2 == 1)
		{
			pthread_mutex_lock(&(philos->mutex->fork_mutex[(philos->num + 1) % philos->rule->num]));
			printf("%d has taken a %d right fork\n", philos->num, (philos->num + 1) % philos->rule->num);
			pthread_mutex_lock(&(philos->mutex->fork_mutex[philos->num % philos->rule->num]));
			printf("%d has taken a %d left fork\n", philos->num, philos->num % philos->rule->num);

			pthread_mutex_unlock(&(philos->mutex->fork_mutex[(philos->num + 1) % philos->rule->num]));
			printf("%d put down a right fork\n", philos->num);
			pthread_mutex_unlock(&(philos->mutex->fork_mutex[philos->num % philos->rule->num]));
			printf("%d put down a left fork\n", philos->num);
			printf("%d sleeping\n", philos->num);

			usleep(philos->rule->time_to_sleep * 1000);


		}
		i++;
	}
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

	int i = rules->num - 1;
	while(i > 0)
	{
		pthread_join(philos[i]->tid, NULL);
		i--;
	}

	return (0);
}

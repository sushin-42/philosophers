#include "philo.h"

t_philo	**philo_structure(t_rule *rules, char *av_1)
{
	t_philo	**philos;
	int		num;
	int		i;
	int		thr_err_chk;
	struct timeval	start;
	struct timeval	end;

	num = ft_atoi(av_1);
	philos = (t_philo **)malloc(sizeof(t_philo *) * num);
	gettimeofday(&start, NULL);
	i = -1;
	while (i++ < num - 1)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		thr_err_chk = pthread_create(&(philos[i]->tid), NULL, t_function, (void *)philos[i]);
		pthread_create_error_check(thr_err_chk);
		philos[i]->rule = rules;
		philos[i]->num = num;
		// sleep(1);
	}
	gettimeofday(&end, NULL);
	printf("%ld\n", (end.tv_sec - start.tv_sec));
	printf("%d\n", (end.tv_usec - start.tv_usec) / 1000);
	return (philos);
}

void	*t_function(void *data)
{
	pid_t	pid;
	t_philo	*philos;
	int		i;


	pid = getpid();
	philos = (t_philo *)data;
	i = 0;
	while (i < 5)
	{
		printf("pid = %d, tid = %x, i = %d\n", pid, (unsigned int)(philos->tid), i);
		i++;
		sleep(1);
	}
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
	return (rules);
}

t_mutex	*mutex_structure()
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(mutex));
	mutex->state = sleeping;
	return (mutex);
}

int		main(int ac, char **av)
{
	t_philo	**philos;
	t_rule	*rules;
	t_mutex	*mutex;

	if (ac != 5 && ac != 6)
		return (printf("arguments error\n"));
	rules = rule_structure(av);
	philos = philo_structure(rules, av[1]);
	mutex = mutex_structure();

	// //현재 시간을 얻어온다.
	// gettimeofday(&starttime, NULL);
	// printf("%ld:%d\n", starttime.tv_sec, starttime.tv_usec);
	// usleep(5000);

	return (0);
}


// philosopher == 1 time_to_die


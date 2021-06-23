#include "philo.h"

t_philo	**philo_structure(t_rule *rules, char *av_1)
{
	t_philo	**philos;
	int	num;
	int	i;

	num = ft_atoi(av_1);
	philos = (t_philo **)malloc(sizeof(t_philo *) * num);
	i = -1;
	while (i++ < num - 1)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->rule = rules;
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
	return (rules);
}

int		main(int ac, char **av)
{
	t_philo	**philos;
	t_rule	*rules;

	if (ac != 5)
		return (printf("arguments error\n"));
	rules = rule_structure(av);
	philos = philo_structure(rules, av[1]);
	// //현재 시간을 얻어온다.
	// gettimeofday(&starttime, NULL);
	// printf("%ld:%d\n", starttime.tv_sec, starttime.tv_usec);
	// usleep(5000);
	return (0);
}


// philosopher == 1 time_to_die


#include "philo.h"

void	*philo_act(void *data)
{
	t_philo	*philos;
	philos = (t_philo *)data;
	gettimeofday(&(philos->eat_time), NULL);
	while(1)
	{
		take_fork(philos);
		act_eat(philos);
		putdown_fork(philos);
		if (philos->eat_cnt >= philos->rule->must_eat && philos->rule->must_eat != -1)
			break;
		act_sleep(philos);
		act_think(philos);
	}
	return (NULL);
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

	monitor_philo(philos);
	return (0);
}

#include "philo.h"

void	*philo_act(void *data)
{
	t_philo	*philos;
	int i = 0;
	philos = (t_philo *)data;
	while(i < 3)
	{
		take_fork(philos);
		act_eat(philos);
		putdown_fork(philos);
		act_sleep(philos);
		i++;
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

	while(1);
	return (0);
}

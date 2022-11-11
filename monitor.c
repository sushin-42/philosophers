#include "philo.h"

int	check_alive(t_philo **philos)
{
	long int		timepast;
	struct timeval	check_death;
	int				i;

	i = 0;
	while (i < (*philos)->rule->num)
	{
		gettimeofday(&check_death, NULL);
		timepast = (check_death.tv_sec - philos[i]->eat_time.tv_sec) * 1000
			 + (check_death.tv_usec - philos[i]->eat_time.tv_usec) / 1000;
		if (timepast > (long int)(philos[i]->rule->time_to_die))
		{
			writing(philos[i], DIE);
			philos[i]->rule->die_check = 1;
			return (1);
		}
		usleep(100);
		i++;
	}
	return (0);
}

void	die_monitor(t_philo **philos)
{
	
	while (1)
	{
		if (check_alive(philos) == 1)
			break ;
	}
}

void	eat_monitor(t_philo **philos)
{
	int		p_num;
	int		i;

	i = 0;
	p_num = (*philos)->rule->num;
	while (!check_alive(philos) && i < p_num)
	{
		if (philos[i]->eat_cnt >= (*philos)->rule->must_eat)
			i++;
	}
	if (!((*philos)->rule->die_check))
		printf("all philosopher ate %d times\n", (*philos)->rule->must_eat);
}

void	monitor_philo(t_philo **philos)
{
	if ((*philos)->rule->must_eat >= 0)
		eat_monitor(philos);
	else
		die_monitor(philos);
}

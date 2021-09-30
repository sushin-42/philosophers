#include "philo.h"

void	take_fork(t_philo *philos)
{
	pthread_mutex_lock(philos->r_fork);
	pthread_mutex_lock(philos->l_fork);
	writing(philos, RFORK);
	writing(philos, LFORK);
}

void	putdown_fork(t_philo *philos)
{
	pthread_mutex_unlock(philos->r_fork);
	pthread_mutex_unlock(philos->l_fork);
}

void	act_eat(t_philo *philos)
{
	gettimeofday(&(philos->eat_time), NULL);
	writing(philos, EAT);
	philos->eat_cnt++;
	div_usleep(philos->rule->time_to_eat);
}

void	act_sleep(t_philo *philos)
{
	writing(philos, SLEEP);
	div_usleep(philos->rule->time_to_sleep);
}

void	act_think(t_philo *philos)
{
	writing(philos, THINK);
}

#include "philo.h"

void	take_fork(t_philo *philos)
{
		pthread_mutex_lock(&(philos->l_fork));
		writing(philos, LFORK);
		pthread_mutex_lock(&(philos->r_fork));
		writing(philos, RFORK);

}

void	putdown_fork(t_philo *philos)
{
		pthread_mutex_unlock(&(philos->l_fork));
		writing(philos, PLFORK);
		pthread_mutex_unlock(&(philos->r_fork));
		writing(philos, PRFORK);
}

void	act_eat(t_philo *philos)
{
	usleep(philos->rule->time_to_eat * 1000);
	writing(philos, EAT);
}

void	act_sleep(t_philo *philos)
{
	usleep(philos->rule->time_to_sleep * 1000);
}

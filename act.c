#include "philo.h"

void	take_fork(t_philo *philos)
{
		pthread_mutex_lock(philos->l_fork);
		writing(philos, LFORK);
		pthread_mutex_lock(philos->r_fork);
		writing(philos, RFORK);

}

void	putdown_fork(t_philo *philos)
{
		pthread_mutex_unlock(philos->l_fork);
		writing(philos, PLFORK);
		pthread_mutex_unlock(philos->r_fork);
		writing(philos, PRFORK);
}

void	act_eat(t_philo *philos)
{
	writing(philos, EAT);
	div_usleep(philos->rule->time_to_eat);
}

void	act_sleep(t_philo *philos)
{

	writing(philos, SLEEP);
	div_usleep(philos->rule->time_to_sleep);
}

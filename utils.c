#include "philo.h"

void	writing(t_philo *philos, int state)
{
	pthread_mutex_lock(&(philos->mutex->writing_mutex));
	if (state == 1)
		printf("%d is eating \n", philos->num);
	else if (state == 2)
		printf("%d is sleeping \n", philos->num);
	else if (state == 3)
		printf("%d is thinking \n", philos->num);
	else if (state == 4)
		printf("%d has taken a left fork\n", philos->num);
	else if (state == 5)
		printf("%d has taken a right fork\n", philos->num);
	else if (state == 6)
		printf("%d put down right fork\n", philos->num);
	else if (state == 7)
		printf("%d put down right fork\n", philos->num);
	pthread_mutex_unlock(&(philos->mutex->writing_mutex));
}

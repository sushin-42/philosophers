#include "philo.h"

void	div_usleep(long int time)
{
	struct timeval	starttime;
	struct timeval	checktime;
	long int check = 0;

	gettimeofday(&starttime, NULL);
	while (check <= time)
	{
		usleep(100);
		gettimeofday(&checktime, NULL);
		check = timediff(&starttime, &checktime);
	}

}




long int	timediff(struct timeval *start, struct timeval *end)
{
	long int endtime;
	long int starttime;

	endtime = (end->tv_sec * 1000) + end->tv_usec / 1000;

	starttime = (start->tv_sec * 1000) + start->tv_usec / 1000;
	return (endtime - starttime);
}

void	writing(t_philo *philos, int state)
{
	struct timeval	current_time;
	long int	printtime;

	gettimeofday(&current_time, NULL);
	printtime = timediff(&(philos->start), &current_time);

	pthread_mutex_lock(&(philos->mutex->writing_mutex));
	if (state == 1)
		printf("%ldms %d is eating \n", printtime, philos->num);
	else if (state == 2)
		printf("%ldms %d is sleeping \n", printtime, philos->num);
	else if (state == 3)
		printf("%ldms %d is thinking \n", printtime, philos->num);
	else if (state == 4)
		printf("%ldms %d has taken a left fork\n", printtime, philos->num);
	else if (state == 5)
		printf("%ldms %d has taken a right fork\n", printtime, philos->num);
	else if (state == 6)
		printf("%ldms %d put down right fork\n", printtime, philos->num);
	else if (state == 7)
		printf("%ldms %d put down right fork\n", printtime, philos->num);
	else if (state == 8)
		printf("%ldms %d died\n", printtime, philos->num);
	pthread_mutex_unlock(&(philos->mutex->writing_mutex));
}

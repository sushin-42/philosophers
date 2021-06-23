#include "philo.h"

int	main()
{
	struct timeval	starttime;
	struct timeval	endtime;

	// 현재 시간을 얻어온다.
	gettimeofday(&starttime, NULL);
	printf("%ld:%d\n", starttime.tv_sec, starttime.tv_usec);
	sleep (5);
	gettimeofday(&endtime, NULL);
	printf("%ld:%d\n", endtime.tv_sec, endtime.tv_usec);
	printf("diff time is = %ld\n%d", (endtime.tv_sec - starttime.tv_sec),(endtime.tv_usec - starttime.tv_usec));
	return 0;
}


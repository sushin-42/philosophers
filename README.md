# Philosophers

## *Sumarry*
In this project, you will learn the basics of threading a process. <br/>
You will see how to create threads and you will discover mutexes.

## How to use it
```
$> make

 * Execute
$> ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [option: number_of_times_each_philosopher_must_eat]
```

## Rules
* must not have any data races.
* philosophers must eat, sleep, or think.
* you should avoid to die philo.
* philo is diying after he/she started to eat.

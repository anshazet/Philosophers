/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:29:31 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/18 13:59:42 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(char *str, t_philo *i)
{
	struct timeval	current_time;
	long			time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	sem_wait(i->print);
	sem_wait(i->die);
	printf("%ld %zu %s\n", time - i->timestart, i->ph, str);
	sem_post(i->die);
	sem_post(i->print);
}

void	ft_isdead(t_philo *i)
{
	struct timeval	current_time;
	long			time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	if (time - i->timedie > 0)
	{
		sem_wait(i->die);
		printf("%ld %zu died\n", time - i->timestart, i->ph);
		exit(1);
	}
}

void	ft_eat(t_philo *i)
{
	struct timeval	current_time;
	long			time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is eating", i);
	while (1)
	{
		usleep(200);
		ft_isdead(i);
		if (ft_checktime(time) >= i->time_to_eat)
			break ;
	}
	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	i->timedie = time + i->time_to_die;
	i->nbr_of_eat--;
}

void	ft_sleep(t_philo *i)
{
	long			time;
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is sleeping", i);
	while (1)
	{
		usleep(200);
		if (ft_checktime(time) >= i->time_to_sleep)
			break ;
	}
	ft_print("is thinking", i);
}

void	ft_free_info(t_philo *data)
{
	free(data->id);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/die");
	sem_unlink("/start");
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->die);
	sem_close(data->start);
}
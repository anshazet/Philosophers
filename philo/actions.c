/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:29:31 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/06 12:38:03 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str, t_philo i)
{
	struct timeval	current_time;
	long			time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	pthread_mutex_lock (&i.printmutex[0]);
	if (i.isdead[0])
		printf("%ld %zu %s\n", time - i.timestart, i.ph, str);
	pthread_mutex_unlock (&i.printmutex[0]);
}

void	ft_isdead(t_philo *i)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	pthread_mutex_lock(&i->printmutex[0]);
	if (i->isdead[0])
	{
		if (time - i->timedie > 0)
		{
			printf("%ld %zu is died ☠️\n", time - i->timestart, i->ph);
			i->isdead[0] = 0;
		}
	}
	pthread_mutex_unlock(&i->printmutex[0]);
}

void	ft_eat(t_philo *i)
{
	long			time;
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is eating 🍝", *i);
	while (1)
	{
		usleep(100);
		ft_isdead(i);
		pthread_mutex_lock(&i->printmutex[0]);
		if (ft_checktime(time) >= i->time_to_eat)
		{
			pthread_mutex_unlock(&i->printmutex[0]);
			break ;
		}
		else
			pthread_mutex_unlock(&i->printmutex[0]);
	}
	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	pthread_mutex_lock(&i->printmutex[0]);
	i->timedie = time + i->time_to_die;
	i->nbr_of_eat--;
	pthread_mutex_unlock(&i->printmutex[0]);
}

void	ft_sleep(t_philo *i)
{
	long			time;
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is sleeping 😴", *i);
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(&i->printmutex[0]);
		if (ft_checktime(time) >= i->time_to_sleep)
		{
			pthread_mutex_unlock(&i->printmutex[0]);
			break ;
		}
		else
			pthread_mutex_unlock(&i->printmutex[0]);
	}
	ft_print("is thinking 🤯", *i);
}

size_t	ft_checktime(long ref)
{
	struct timeval	current_time;
	long			now;

	gettimeofday (&current_time, NULL);
	now = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (now - ref);
}

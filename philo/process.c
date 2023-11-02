/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:56:43 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/07 07:20:46 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdead(t_philo i)
{
	pthread_mutex_lock(&i.printmutex[0]);
	if (i.isdead[0])
	{
		pthread_mutex_unlock(&i.printmutex[0]);
		return (1);
	}
	pthread_mutex_unlock(&i.printmutex[0]);
	return (0);
}

void	ft_run(t_philo i)
{
	while (ft_checkdead(i))
	{
		pthread_mutex_lock (&i.mutex[i.rf]);
		ft_print("has taken a fork 🍴", i);
		usleep(50);
		pthread_mutex_lock (&i.mutex[i.lf]);
		ft_print("has taken a fork 🍴", i);
		ft_eat(&i);
		pthread_mutex_unlock (&i.mutex[i.lf]);
		pthread_mutex_unlock (&i.mutex[i.rf]);
		ft_sleep(&i);
		pthread_mutex_lock(&i.printmutex[0]);
		if (!i.nbr_of_eat)
		{
			pthread_mutex_unlock(&i.printmutex[0]);
			break ;
		}
		else
			pthread_mutex_unlock(&i.printmutex[0]);
	}
}

void	*ft_process(void	*data)
{
	struct timeval	current_time;
	t_philo			i;

	i = *(t_philo *) data;
	ft_mutex_forks(&i);
	ft_mutex_checktime (&i);
	pthread_mutex_lock(&i.printmutex[0]);
	gettimeofday (&current_time, NULL);
	i.timestart = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	i.timedie = i.timestart + i.time_to_die;
	if (i.ph % 2 == 1)
		usleep(1000);
	pthread_mutex_unlock(&i.printmutex[0]);
	ft_run(i);
	return (NULL);
}

void	ft_mutex_forks(t_philo *i)
{
	pthread_mutex_lock(&i->printmutex[0]);
	if (i->ph % 2 != 0)
	{
		i->lf = i->ph;
		i->rf = i->ph + 1;
		if (i->ph == i->total_ph)
			i->rf = 1;
	}
	else
	{
		i->lf = i->ph + 1;
		i->rf = i->ph;
		if (i->ph == i->total_ph)
			i->lf = 1;
	}
	pthread_mutex_unlock(&i->printmutex[0]);
}

void	ft_mutex_checktime(t_philo *i)
{
	while (1)
	{
		pthread_mutex_lock(&i->printmutex[0]);
		if (ft_checktime(i->timestart) >= 1000)
		{
			pthread_mutex_unlock(&i->printmutex[0]);
			break ;
		}
		else
			pthread_mutex_unlock(&i->printmutex[0]);
		usleep(300);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:56:43 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/19 08:38:08 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_run(t_philo *i)
{
	while (1)
	{
		sem_wait(i->forks);
		ft_print("has taken a fork", i);
		usleep(50);
		sem_wait(i->forks);
		ft_print("has taken a fork", i);
		ft_eat(i);
		sem_post(i->forks);
		sem_post(i->forks);
		ft_sleep(i);
		if (!i->nbr_of_eat)
			break ;
	}
	exit (0);
}

void	ft_process(t_philo *i)
{
	struct timeval	current_time;

	if (i->ph != i->total_ph)
		sem_wait(i->start);
	sem_post(i->start);
	gettimeofday (&current_time, NULL);
	i->timestart = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	i->timedie = i->timestart + i->time_to_die;
	if (i->ph % 2 == 1)
		usleep(1000);
	ft_run(i);
}

size_t	ft_checktime(long ref)
{
	struct timeval	current_time;
	long			now;

	gettimeofday (&current_time, NULL);
	now = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (now - ref);
}

void	ft_kill(t_philo data)
{
	size_t	i;

	i = 1;
	while (i <= data.total_ph)
	{
		kill(data.id[i], SIGKILL);
		i++;
	}
}

void	ft_wait(t_philo data)
{
	int		status;

	data.ph = 1;
	while (data.ph <= data.total_ph)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			ft_kill(data);
			break ;
		}
		data.ph++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:05 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/06 12:47:43 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_args(t_philo *data, int ac, char **av)
{
	data->total_ph = (size_t) ft_atoi_long(av[1]);
	data->time_to_die = (size_t) ft_atoi_long(av[2]);
	data->time_to_eat = (size_t) ft_atoi_long(av[3]);
	data->time_to_sleep = (size_t) ft_atoi_long(av[4]);
	if (ac == 6)
		data->nbr_of_eat = (size_t) ft_atoi_long(av[5]);
	return (0);
}

int	ft_onephilo(t_philo data)
{
	if (data.total_ph == 1)
	{
		printf("0 1 has taken a fork 🍴\n");
		usleep(data.time_to_die * 1000);
		printf("%s%lu 1 is died ☠️%s\n", RB, data.time_to_die, RC);
		return (1);
	}
	return (0);
}

void	ft_init_data(t_philo *data)
{
	struct timeval	current_time;
	size_t			i;

	gettimeofday (&current_time, NULL);
	data->timestart = (current_time.tv_sec * 1000) + \
		(current_time.tv_usec / 1000);
	data->timestart = data->timestart + 1000;
	data->id = malloc((data->total_ph + 1) * sizeof(pthread_t));
	data->isdead = malloc(sizeof(int));
	data->isdead[0] = 1;
	data->mutex = malloc((data->total_ph + 1) * sizeof(pthread_mutex_t));
	i = 0;
	while (i < data->total_ph + 1)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
	data->printmutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->printmutex[0], NULL);
}

void	ft_free_info(t_philo *data)
{
	size_t	i;

	free(data->id);
	free(data->isdead);
	i = 0;
	while (i < data->total_ph + 1)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
	pthread_mutex_destroy(&data->printmutex[0]);
	free(data->printmutex);
}

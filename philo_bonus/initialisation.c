/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:18:05 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/03 14:23:13 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int ft_init_args (t_philo *data, int ac, char **av)
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
		printf("0 1 has taken a fork\n");
		usleep(data.time_to_die * 1000);
		printf("%lu 1 died\n", data.time_to_die);
		return (1);
	}
	return (0);
}

void	ft_init_data(t_philo *data)
{
	data->id = malloc((data->total_ph + 1) * sizeof(int));
	memset(data->id, 0, data->total_ph + 1);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/die");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->total_ph);
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	data->die = sem_open("/die", O_CREAT, 0644, 1);
	data->start = sem_open("/start", O_CREAT, 0644, 0);
}
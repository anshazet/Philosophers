/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:26:51 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/07 07:20:48 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	data;

	if (ft_check_args_is_valid(ac, av))
		return (1);
	if (ft_check_args_is_valid_2(ac, av))
		return (1);
	ft_init_args(&data, ac, av);
	if (ft_onephilo(data))
		return (0);
	ft_init_data(&data);
	start_threads(&data);
	ft_free_info(&data);
	return (0);
}

void	start_threads(t_philo *data)
{
	int	x;
	int	z;

	z = data->total_ph;
	x = 1;
	data->ph = 1;
	while (x <= z)
	{
		pthread_create(&data->id[x], NULL, ft_process, (void *)data);
		usleep(100);
		pthread_mutex_lock(&data->printmutex[0]);
		x++;
		data->ph++;
		pthread_mutex_unlock(&data->printmutex[0]);
	}
	x = 1;
	while (x <= z)
	{
		pthread_join(data->id[x], NULL);
		x++;
	}
}

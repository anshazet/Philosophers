/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:26:51 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/19 13:43:09 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// valgrind --tool=drd
// valgrind --tool=helgrind

int	main(int ac, char **av)
{
    t_philo data;
    
    if (ft_check_args_is_valid(ac, av))
		  return (1);
    if (ft_check_args_is_valid_2(ac, av))
		  return (1);
    ft_init_args (&data, ac, av);
    if (ft_onephilo(data))
        return (0);
    ft_init_data (&data);
    data.ph = 1;
    while (data.ph <= data.total_ph)
    {
        data.id[data.ph] = fork();
        if (data.id[data.ph] == 0)
            ft_process(&data);
        data.ph++;
    }
    ft_wait(data);
    ft_free_info(&data);
    return (0);   
}

/*
❌⛔️❗️
🧐😴😋
⚰️🪦
🤯😵☠️💀
🍝🍽️🍴
🥄🥸😵‍💫
*/
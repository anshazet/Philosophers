/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 07:37:46 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/07 07:21:46 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi_long(char *str)
{
	long long int	i;
	long int		signe;
	long int		result;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * signe);
}

void	print_parameter(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		printf("Parameter passed: %s\n", av[i]);
		i++;
	}
}

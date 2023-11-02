/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 07:31:54 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/07 07:22:26 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_check_args(void)
{
	printf("%sPlease enter 4 or 5 arguments:\n", RB);
	printf("\n");
	printf("[1] : Number of philosophers\n");
	printf("[2] : Time to live\n");
	printf("[3] : Time to eat\n");
	printf("[4] : Time to sleep\n");
	printf("[5] : Number of eatings\n");
}

int	ft_check_args_is_valid(int ac, char **av)
{
	size_t		i;
	long long	param_value;

	if (ac < 5 || ac > 6)
	{
		ft_check_args();
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (!ft_is_digit(av[i]) || (!ft_atoi_long(av[i])))
		{
			printf("%s❌ Invalid argument: %s%s\n", RB, av[i], RC);
			return (1);
		}
		param_value = ft_atoi_long(av[i]);
		if (param_value > 2147483647 || param_value < -2147483648)
		{
			printf("%s❌ Error! Parameter exceeds int min/max%s\n", RB, RC);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args_is_valid_2(int ac, char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi_long(av[1]) > 200)
		{
			printf("%s❌ Error! More than 200 philo%s\n", RB, RC);
			return (1);
		}
		if ((ft_atoi_long(av[2]) < 60) || (ft_atoi_long(av[3]) < 60) \
				|| (ft_atoi_long(av[4]) < 60))
		{
			printf("%s❌ Error! Do not test less than 60ms%s\n", RB, RC);
			return (1);
		}
		i++;
	}
	return (0);
}

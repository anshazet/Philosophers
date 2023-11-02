/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:27:00 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/07 07:21:13 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <string.h>

# define ERROR 1
# define VALID 0

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define BK "\001\033[0;30m\002"
# define R "\001\033[0;31m\002"
# define G "\001\033[0;32m\002"
# define Y "\001\033[0;33m\002"
# define B "\001\033[0;34m\002"
# define P "\001\033[0;35m\002"
# define C "\001\033[0;36m\002"
# define W "\001\033[0;37m\002"

/* Bold */
# define BKB "\001\033[1;30m\002"
# define RB "\001\033[1;31m\002"
# define GB "\001\033[1;32m\002"
# define YB "\001\033[1;33m\002"
# define BB "\001\033[1;34m\002"
# define PB "\001\033[1;35m\002"
# define CB "\001\033[1;36m\002"
# define WB "\001\033[1;37m\002"

/* Reset Color */
# define RC "\001\033[0m\002"

typedef struct s_philo
{
	pthread_t		*id;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*printmutex;
	size_t			ph;
	int				*isdead;
	long			timestart;
	long			timedie;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			lf;
	size_t			rf;
	size_t			nbr_of_eat;
	size_t			total_ph;
}	t_philo;

/* errors */
int			ft_is_digit(char *str);
void		ft_check_args(void);
int			ft_check_args_is_valid(int ac, char **av);
int			ft_check_args_is_valid_2(int ac, char **av);

/* initialisation */
int			ft_init_args(t_philo *data, int ac, char **av);
int			ft_onephilo(t_philo data);
void		ft_init_data(t_philo *data);
void		ft_free_info(t_philo *data);

/* utils */
long int	ft_atoi_long(char *str);

/* philo */
void		start_threads(t_philo *data);

/* process */
int			ft_checkdead(t_philo i);
void		*ft_process(void	*data);
void		ft_run(t_philo i);
void		ft_mutex_forks(t_philo *i);
void		ft_mutex_checktime(t_philo *i);

/* actions */
void		ft_print(char *str, t_philo i);
void		ft_isdead(t_philo *i);
void		ft_eat(t_philo *i);
void		ft_sleep(t_philo *i);
size_t		ft_checktime(long ref);

#endif

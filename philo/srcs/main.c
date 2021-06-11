/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:38:08 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/11 13:49:31 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void*		start_philo(void* thread)
{
	t_philo *philo;
	unsigned int reset;

	philo = (t_philo *)thread;
	reset = philo->arg.time_start;
	while (philo->data->is_philo_dead == false)
	{
		philo->time_without_eat = get_time(false, reset);
		if ((int)philo->time_without_eat >= philo->arg.time_die)
		{
			display_status(philo, "DIE");
			philo->data->is_philo_dead = true;
			pthread_mutex_lock(&philo->data->display);
			break;
		}
		action_eat(philo, &reset);
		action_sleep(philo);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_data data;

	if (ac < 5 || ac > 6)
		exit_err(1, &data);
	if (!check_args(++av))
		exit_err(2, &data);
	if (!init(&data, av, ac))
		exit_err(3, &data);
	// if (data.nb_philo < 2)
	// 	exit_err(4, &data);
	if (!init_thread(&data))
		exit_err(5, &data);
	return (0);
}
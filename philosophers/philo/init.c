/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:07 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/21 17:05:09 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_philo *phi, char **argv)
{
	phi->max_meal = -1;
	phi->nb_phi = ft_atoi(argv[1]);
	if (phi->nb_phi < 1 || phi->nb_phi > 200)
		return (printf("put a number of philo between 1 and 200"), 1);
	phi->ti_died = ft_atoi(argv[2]);
	phi->ti_eat = ft_atoi(argv[3]);
	phi->ti_sleep = ft_atoi(argv[4]);
	if (argv[5])
		phi->max_meal = ft_atoi(argv[5]);
	phi->is_dead = 0;
	phi->start_pg = get_time();
	if (pthread_mutex_init(&phi->mut_print, NULL) != 0)
		return (1);
	return (0);
}

int	init_phi(t_phi *ph, t_philo *struc)
{
	int	i;

	i = 0;
	while (i < struc->nb_phi)
	{
		ph[i].wh_phi = i + 1;
		ph[i].nb_meal = 0;
		ph[i].ti_lt_meal = 0;
		if (pthread_mutex_init(&ph[i].l_fork, NULL) != 0)
			return (1);
		ph[i].r_fork = &ph[(i + 1) % struc->nb_phi].l_fork;
		ph[i].data = struc;
		ph[i].ti_lt_meal = get_time();
		i++;
	}
	return (0);
}

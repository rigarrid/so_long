/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:21:39 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/25 15:30:10 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

void	ft_matrix(t_map *world)
{
	close(world->fd);
	world->map = (char **)ft_calloc(sizeof(char *) * (world->mass.y + 1), 1);
	world->map2 = (char **)ft_calloc(sizeof(char *) * (world->mass.y + 1), 1);
	world->fd = open("test.ber", O_RDONLY);
}

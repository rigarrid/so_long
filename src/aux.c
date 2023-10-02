/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:21:39 by rigarrid          #+#    #+#             */
/*   Updated: 2023/10/02 16:05:55 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Funcion que crea una matriz y prepara el file descriptor
*/

void	ft_matrix(t_mlx *world)
{
	close(world->fd);
	world->map = (char **)ft_calloc(sizeof(char *) * (world->mass.y + 1), 1);
	world->map2 = (char **)ft_calloc(sizeof(char *) * (world->mass.y + 1), 1);
	world->fd = open(world->hold.file, O_RDONLY);
}

/*
Funcion que comprueba que el archivo tiene la extension adecuada
*/

void	ft_check_file_name(char *file)
{
	int	count;

	count = 0;
	while (file[count])
		count++;
	if (count < 4)
		ft_error(6);
	count -= 4;
	if (file[count++] != '.')
		ft_error(6);
	if (file[count++] != 'b')
		ft_error(6);
	if (file[count++] != 'e')
		ft_error(6);
	if (file[count] != 'r')
		ft_error(6);
}

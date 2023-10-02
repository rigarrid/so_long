/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:04:41 by rigarrid          #+#    #+#             */
/*   Updated: 2023/10/02 16:04:08 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Gestión de errores
*/

int	ft_error(int ne)
{
	if (ne > 0)
	{
		if (ne == 1)
			ft_printf("ERROR.\nWrong map.\n");
		else if (ne == 2)
			ft_printf("ERROR.\nThe map its not sorrounded by walls.\n");
		else if (ne == 3)
			ft_printf("ERROR\nThere is a wrong character in the map\n");
		else if (ne == 4)
			ft_printf("ERROR\nThere is a problem with the exit/start/coins\n");
		else if (ne == 5)
			ft_printf("Error with the fd\n");
		else if (ne == 6)
			ft_printf("ERROR\nIncorret file extension\n");
		else if (ne == 7)
			ft_printf("ERROR\nInvalid number of arguments\n");
		exit(0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:17:37 by klin              #+#    #+#             */
/*   Updated: 2018/03/21 17:47:36 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_put_usage(void)
{
	ft_putendl("usage: ./wolf3d [map_file]");
	return (0);
}

int		map_error(t_env *env)
{
	int		i;

	ft_putendl("Map error");
	if ((*env).map)
	{
		i = 0;
		while (i < (*env).map_h)
		{
			free((*env).map[i]);
			i++;
		}
		free((*env).map);
	}
	exit(0);
	return (0);
}

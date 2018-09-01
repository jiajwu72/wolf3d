/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:21:37 by klin              #+#    #+#             */
/*   Updated: 2018/03/21 17:39:18 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		move_up_down(int key, t_env *e)
{
	if (key == 126)
	{
		if ((*e).map[(int)((*e).player.posx + (*e).player.dirx
					* (*e).player.speed_move)][(int)(*e).player.posy] == 0)
			(*e).player.posx += (*e).player.dirx * (*e).player.speed_move;
		if (e->map[(int)(*e).player.posx][(int)((*e).player.posy
					+ (*e).player.diry * (*e).player.speed_move)] == 0)
			(*e).player.posy += (*e).player.diry * (*e).player.speed_move;
	}
	else if (key == 125)
	{
		if ((*e).map[(int)((*e).player.posx - (*e).player.dirx
					* (*e).player.speed_move)][(int)((*e).player.posy)] == 0)
			(*e).player.posx -= (*e).player.dirx * (*e).player.speed_move;
		if ((*e).map[(int)((*e).player.posx)][(int)((*e).player.posy -
					(*e).player.diry * (*e).player.speed_move)] == 0)
			(*e).player.posy -= (*e).player.diry * (*e).player.speed_move;
	}
	return (0);
}

int		move_left(int key, t_env *e)
{
	double	old_dirx;
	double	old_planex;

	if (key == 123)
	{
		old_dirx = (*e).player.dirx;
		(*e).player.dirx = (*e).player.dirx * cos((*e).player.speed_rot) -
			(*e).player.diry * sin((*e).player.speed_rot);
		(*e).player.diry = old_dirx * sin((*e).player.speed_rot) +
			(*e).player.diry * cos((*e).player.speed_rot);
		old_planex = (*e).player.planex;
		(*e).player.planex = (*e).player.planex * cos((*e).player.speed_rot) -
			(*e).player.planey * sin((*e).player.speed_rot);
		(*e).player.planey = old_planex * sin((*e).player.speed_rot) +
			(*e).player.planey * cos((*e).player.speed_rot);
	}
	return (0);
}

int		move_right(int key, t_env *e)
{
	double	old_dirx;
	double	old_planex;

	if (key == 124)
	{
		old_dirx = (*e).player.dirx;
		(*e).player.dirx = (*e).player.dirx * cos(-(*e).player.speed_rot) -
			(*e).player.diry * sin(-(*e).player.speed_rot);
		(*e).player.diry = old_dirx * sin(-(*e).player.speed_rot) +
			(*e).player.diry * cos(-(*e).player.speed_rot);
		old_planex = (*e).player.planex;
		(*e).player.planex = (*e).player.planex * cos(-(*e).player.speed_rot) -
			(*e).player.planey * sin(-(*e).player.speed_rot);
		(*e).player.planey = old_planex * sin(-(*e).player.speed_rot) +
			(*e).player.planey * cos(-(*e).player.speed_rot);
	}
	return (0);
}

int		quitte(int key, t_env *e)
{
	if (key == 53)
	{
		ft_putendl("Exit success");
		mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win);
		exit(0);
	}
	return (0);
}

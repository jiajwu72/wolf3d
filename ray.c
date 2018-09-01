/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:22:32 by klin              #+#    #+#             */
/*   Updated: 2018/03/23 13:21:24 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_ray(t_env *e, int x)
{
	int		i;

	(*e).line_height = (int)(HEIGHT / (*e).ray.perp_wall_dist)
	* (*e).ray.wall_height;
	(*e).draw_start = -(*e).line_height / 2 + HEIGHT / 2;
	if ((*e).draw_start < 0)
		(*e).draw_start = 0;
	(*e).draw_end = (*e).line_height / 2 + HEIGHT / 2;
	if ((*e).draw_end >= HEIGHT)
		(*e).draw_end = HEIGHT - 1;
	draw_line(e, x);
	i = -1;
	while (++i < (*e).draw_start)
		(*e).mlx.data[WIDTH * i + x] = 0x4db8ff;
}

static void		hit_side_dist(t_env *e)
{
	while ((*e).ray.hit == 0)
	{
		if ((*e).ray.sidex < (*e).ray.sidey)
		{
			(*e).ray.sidex += (*e).ray.deltax;
			(*e).ray.mapx += (*e).ray.stepx;
			(*e).ray.side = 0;
		}
		else
		{
			(*e).ray.sidey += (*e).ray.deltay;
			(*e).ray.mapy += (*e).ray.stepy;
			(*e).ray.side = 1;
		}
		if ((*e).map[(*e).ray.mapx][(*e).ray.mapy] > 0)
			(*e).ray.hit = 1;
	}
	if ((*e).ray.side == 0)
		(*e).ray.perp_wall_dist = ((*e).ray.mapx - (*e).player.posx
				+ (1 - (*e).ray.stepx) / 2) / (*e).ray.raydirx;
	else
		(*e).ray.perp_wall_dist = ((*e).ray.mapy - (*e).player.posy
				+ (1 - (*e).ray.stepy) / 2) / (*e).ray.raydiry;
}

static void		calcule_step(t_env *env)
{
	if ((*env).ray.raydirx < 0)
	{
		(*env).ray.stepx = -1;
		(*env).ray.sidex = ((*env).player.posx - (int)(*env).player.posx)
			* (*env).ray.deltax;
	}
	else
	{
		(*env).ray.stepx = 1;
		(*env).ray.sidex = ((int)(*env).player.posx + 1 - (*env).player.posx)
			* (*env).ray.deltax;
	}
	if ((*env).ray.raydiry < 0)
	{
		(*env).ray.stepy = -1;
		(*env).ray.sidey = ((*env).player.posy - (int)(*env).player.posy)
			* (*env).ray.deltay;
	}
	else
	{
		(*env).ray.stepy = 1;
		(*env).ray.sidey = ((int)(*env).player.posy + 1 - (*env).player.posy)
			* (*env).ray.deltay;
	}
}

static void		init_ray_val(t_env *env, int x)
{
	(*env).ray.camerax = 2 * x / (double)(WIDTH) - 1;
	(*env).ray.raydirx = (*env).player.dirx + (*env).player.planex
		* (*env).ray.camerax;
	(*env).ray.raydiry = (*env).player.diry + (*env).player.planey
		* (*env).ray.camerax;
	(*env).ray.mapx = (int)(*env).player.posx;
	(*env).ray.mapy = (int)(*env).player.posy;
	(*env).ray.deltax = sqrt(1 + ((*env).ray.raydiry * (*env).ray.raydiry) /
			((*env).ray.raydirx * (*env).ray.raydirx));
	(*env).ray.deltay = sqrt(1 + ((*env).ray.raydirx * (*env).ray.raydirx) /
			((*env).ray.raydiry * (*env).ray.raydiry));
	(*env).ray.hit = 0;
	(*env).ray.side = 0;
}

void			ray(t_env *env)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_val(env, x);
		calcule_step(env);
		hit_side_dist(env);
		draw_ray(env, x);
		x++;
	}
	mlx_put_image_to_window((*env).mlx.mlx_ptr,
	(*env).mlx.win, (*env).mlx.img_ptr, 0, 0);
}

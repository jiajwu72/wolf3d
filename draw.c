/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:24:14 by klin              #+#    #+#             */
/*   Updated: 2018/03/23 13:41:47 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				mode_color(double perp, int color)
{
	int			r;
	int			g;
	int			b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = (color & 0xFF);
	if (perp > 3)
	{
		r = ((color & 0xFF0000) >> 16) / (1 + (perp - 3) / 2);
		g = ((color & 0xFF00) >> 8) / (1 + (perp - 3) / 2);
		b = (color & 0xFF) / (1 + (perp - 3) / 2);
	}
	return ((r << 16) | (g << 8) | (b));
}

static int		get_color(t_env *e, int *tex_coord)
{
	int			color;

	if ((*e).ray.side == 1)
	{
		if (((*e).ray.stepx == -1 && (*e).ray.stepy == -1) ||
				((*e).ray.stepx == 1 && (*e).ray.stepy == -1))
			(*e).texture_num = 0;
		if (((*e).ray.stepx == -1 && (*e).ray.stepy == 1) ||
				((*e).ray.stepx == 1 && (*e).ray.stepy == 1))
			(*e).texture_num = 3;
	}
	else
	{
		if (((*e).ray.stepx == -1 && (*e).ray.stepy == -1) ||
				((*e).ray.stepx == -1 && (*e).ray.stepy == 1))
			(*e).texture_num = 2;
		else
			(*e).texture_num = 1;
	}
	color = (*e).texture[(*e).texture_num][TEX_HEIGHT *
		tex_coord[1] + tex_coord[0]];
	color = mode_color((*e).ray.perp_wall_dist, color);
	return (color);
}

void			draw_line(t_env *e, int x)
{
	double		wall_x;
	int			tex_coord[2];
	int			y;
	int			d;
	int			color;

	if ((*e).ray.side == 0)
		wall_x = (*e).player.posy + (*e).ray.perp_wall_dist * (*e).ray.raydiry;
	else
		wall_x = (*e).player.posx + (*e).ray.perp_wall_dist * (*e).ray.raydirx;
	wall_x -= floor((wall_x));
	tex_coord[0] = (int)(wall_x * (double)TEX_WIDTH);
	if ((*e).ray.side == 0 && (*e).ray.raydirx > 0)
		tex_coord[0] = TEX_WIDTH - tex_coord[0] - 1;
	if ((*e).ray.side == 1 && (*e).ray.raydiry < 0)
		tex_coord[0] = TEX_WIDTH - tex_coord[0] - 1;
	y = (*e).draw_start;
	while (y < (*e).draw_end)
	{
		d = y * 256 - HEIGHT * 128 + (*e).line_height * 128;
		tex_coord[1] = ((d * TEX_WIDTH) / (*e).line_height) / 256;
		color = get_color(e, tex_coord);
		(*e).mlx.data[WIDTH * y + x] = color;
		y++;
	}
}

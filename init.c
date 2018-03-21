/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:46:16 by klin              #+#    #+#             */
/*   Updated: 2018/03/21 15:55:11 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init_player(t_env *e)
{
	(*e).player.posx = 0;
	(*e).player.posy = 0;
	(*e).player.dirx = -1.;
	(*e).player.diry = 0.;
	(*e).player.planex = 0.;
	(*e).player.planey = 0.66;
	(*e).player.speed_rot = 0.03;
	(*e).player.speed_move = 0.05;
}

static void		init_mlx(t_env *e)
{
	(*e).mlx.mlx_ptr = mlx_init();
	(*e).mlx.win = mlx_new_window(e->mlx.mlx_ptr, WIDTH,
			HEIGHT, "wolf3d");
	(*e).mlx.img_ptr = mlx_new_image(e->mlx.mlx_ptr, WIDTH, HEIGHT);
	(*e).mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr,
			&e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
}

static	void	init_texture(t_env *e)
{
	int x;
	int y;
	int color[3];

	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			color[0] = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			color[1] = y * 256 / TEX_HEIGHT;
			color[2] = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			(*e).texture[0][TEX_WIDTH * y + x] = color[2] + 256
				* color[2] + 65536 * color[2];
			(*e).texture[1][TEX_WIDTH * y + x] = 256 * color[2] + 9999 * color[2];
			(*e).texture[2][TEX_WIDTH * y + x] = color[0] + 256
				* color[0] + 65536 * color[0];
			(*e).texture[3][TEX_WIDTH * y + x] = 256 * color[0];
			(*e).texture[4][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16);
			(*e).texture[5][TEX_WIDTH * y + x] = 65536 * color[1];
			y++;
		}
		x++;
	}
}

void			init_env(t_env *e)
{
	init_player(e);
	init_mlx(e);
	init_texture(e);
}

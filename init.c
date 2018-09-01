/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:46:16 by klin              #+#    #+#             */
/*   Updated: 2018/04/18 17:03:33 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	void		init_player(t_env *e)
{
	(*e).player.posx = 0;
	(*e).player.posy = 0;
	(*e).player.dirx = -1.;
	(*e).player.diry = 0.;
	(*e).player.planex = 0.;
	(*e).player.planey = 0.7;
	(*e).player.speed_rot = 0.06;
	(*e).player.speed_move = 0.08;
}

static	void		init_mlx(t_env *e)
{
	(*e).mlx.mlx_ptr = mlx_init();
	(*e).mlx.win = mlx_new_window(e->mlx.mlx_ptr, WIDTH,
			HEIGHT, "wolf3d");
	(*e).mlx.img_ptr = mlx_new_image(e->mlx.mlx_ptr, WIDTH, HEIGHT);
	(*e).mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr,
			&e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
}

static	void		texture(t_env *e, t_image *img, int i)
{
	int			x;
	int			y;

	x = 0;
	while (x < (TEX_WIDTH / 2))
	{
		y = 0;
		while (y < (TEX_HEIGHT / 2))
		{
			(*e).texture[i][TEX_WIDTH * y + x] = get_pixel(img, x, y);
			(*e).texture[i][TEX_WIDTH * y + x +
				(TEX_WIDTH / 2)] = get_pixel(img, x, y);
			(*e).texture[i][TEX_WIDTH * y + x + (TEX_WIDTH *
					(TEX_HEIGHT / 2))] = get_pixel(img, x, y);
			(*e).texture[i][TEX_WIDTH * y + x + (TEX_WIDTH * (TEX_HEIGHT / 2)
					+ (TEX_WIDTH / 2))] = get_pixel(img, x, y);
			y++;
		}
		x++;
	}
}

static	void		init_texture(t_env *e)
{
	int			i;
	t_image		*img[4];

	img[0] = xpm_image("texture/brick.xpm", &(*e).mlx);
	img[1] = xpm_image("texture/metal.xpm", &(*e).mlx);
	img[2] = xpm_image("texture/wood.xpm", &(*e).mlx);
	img[3] = xpm_image("texture/stone.xpm", &(*e).mlx);
	i = 0;
	while (i < 4)
	{
		texture(e, img[i], i);
		i++;
	}
	free(img[0]);
	free(img[1]);
	free(img[2]);
	free(img[3]);
}

void				init_env(t_env *e)
{
	init_player(e);
	init_mlx(e);
	init_texture(e);
	(*e).ray.wall_height = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:13:37 by jwu               #+#    #+#             */
/*   Updated: 2018/04/20 18:15:10 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			msg(void)
{
	ft_putendl("------------Man utilisation Wolf3D----------------");
	ft_putendl("deplacement:				up down left right");
	ft_putendl("changement de vitesse de deplacement:	+ -:");
	ft_putendl("changement de la hauteur des murs:	q w");
}

int				get_pixel(t_image *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (0);
	return (*(int *)(image->ptr + ((x + y * image->width)
											* image->bpp)));
}

t_image			*xpm_image(char *xpm, t_mlx *mlx)
{
	t_image *img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	img->image = mlx_xpm_file_to_image(mlx->mlx_ptr, xpm, &img->width,
			&img->height);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	img->width = img->stride / img->bpp;
	img->height = img->stride / img->bpp;
	return (img);
}

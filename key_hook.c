/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:13:59 by jwu               #+#    #+#             */
/*   Updated: 2018/04/20 19:22:23 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <time.h>

void	clear_img(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			env->mlx.data[WIDTH * x + y] = 0;
			y++;
		}
		x++;
	}
}

int		change_wall(int key, t_env *env)
{
	if (key == 12 && (*env).ray.wall_height < 1.45)
		(*env).ray.wall_height *= 1.1;
	if (key == 13 && (*env).ray.wall_height > 0.5)
		(*env).ray.wall_height /= 1.1;
	return (0);
}

int		change_vitesse(int key, t_env *env)
{
	if (key == 69 && env->player.speed_move < 0.16)
		env->player.speed_move += 0.04;
	if (key == 78)
	{
		if (env->player.speed_move > 0.04)
			env->player.speed_move -= 0.04;
	}
	return (0);
}

int		key_hook(int key, t_env *env)
{
	clear_img(env);
	move_up_down(key, env);
	move_left(key, env);
	move_right(key, env);
	change_vitesse(key, env);
	change_wall(key, env);
	quitte(key, env);
	ray(&(*env));
	return (0);
}

int		close_win(t_env *e)
{
	ft_putendl("Exit success");
	mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win);
	exit(0);
	return (0);
}

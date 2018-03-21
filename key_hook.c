/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:13:59 by jwu               #+#    #+#             */
/*   Updated: 2018/03/21 17:56:04 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

int		key_hook(int key, t_env *env)
{
	clear_img(env);
	move_up_down(key, env);
	move_left(key, env);
	move_right(key, env);
	quitte(key, env);
	ray(&(*env));
	return (0);
}

int		close_win(t_env *e)
{
	ft_putendl("Exit success");
	mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win);
	exit(0);
}

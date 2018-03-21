/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:21 by klin              #+#    #+#             */
/*   Updated: 2018/03/21 17:41:54 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		return (ft_put_usage());
	init_env(&env);
	ft_read(argv[1], &env);
	ray(&env);
	mlx_hook(env.mlx.win, 2, 1L<<0, key_hook, &env);
	mlx_hook(env.mlx.win, 17, 18, close_win, &env);
//	mlx_mouse_hook(mlx->win, mouse_click_hook, &mlx);
//	mlx_hook(mlx->win, 6, (1L << 6), mouse_move_hook, &mlx);
	mlx_loop(env.mlx.mlx_ptr);
	return (0);
}

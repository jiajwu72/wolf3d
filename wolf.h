/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:24:24 by klin              #+#    #+#             */
/*   Updated: 2018/03/21 17:45:59 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 640
# define HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_ESC 53

typedef struct			s_player
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				speed_rot;
	double				speed_move;
}						t_player;

typedef struct			s_ray
{
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidex;
	double				sidey;
	double				deltax;
	double				deltay;
	double				perp_wall_dist;
	int					stepx;
	int					stepy;
	int					side;
	int					hit;
}						t_ray;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_l;
	int					endian;
}						t_mlx;

typedef struct			s_env
{
	struct s_mlx		mlx;
	struct s_player		player;
	struct s_ray		ray;
	int					**map;
	int					map_w;
	int					map_h;
	int					texture[6][TEX_WIDTH * TEX_HEIGHT];
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					texture_num;
}						t_env;
/*
** key_hook
*/
int						move_up_down(int key, t_env *e);
int						move_right(int key, t_env *e);
int						move_left(int key, t_env *e);
int						key_hook(int key, t_env *env);
int						quitte(int key, t_env *e);
/*
**  Exit
*/
int						ft_put_usage(void);
int						close_win(t_env *e);
int						map_error(t_env *env);

void					init_env(t_env *e);
int						ft_read(char *file, t_env *env);
void					ray(t_env *env);
void					draw_line(t_env *env, int x);

#endif

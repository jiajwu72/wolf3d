/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:15:37 by klin              #+#    #+#             */
/*   Updated: 2018/04/20 19:05:37 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		map_info(int fd, t_env *env)
{
	char		*line;
	char		**val;
	int			i;

	get_next_line(fd, &line);
	val = ft_strsplit(line, ' ');
	if ((int)ft_sstrlen(val) != 4 || !ft_str_is_num(val[0])
		|| !ft_str_is_num(val[1]) || !ft_str_is_num(val[2])
		|| !ft_str_is_num(val[3]))
		return (0);
	(*env).map_w = ft_atoi(val[0]);
	(*env).map_h = ft_atoi(val[1]);
	(*env).player.posx = ft_atoi(val[2]) + 0.08;
	(*env).player.posy = ft_atoi(val[3]) + 0.08;
	if ((*env).player.posx >= (*env).map_w || (*env).map_w < 3
		|| (*env).player.posy >= (*env).map_h || (*env).map_h < 3)
		return (0);
	(*env).map = (int **)malloc(sizeof(int *) * (*env).map_h);
	i = 0;
	while (i < (*env).map_h)
		(*env).map[i++] = (int *)malloc(sizeof(int) * (*env).map_w);
	free(line);
	ft_free_sstr(&val);
	return (1);
}

static int		ft_read_width(char **val, int x, t_env *env)
{
	int			y;
	int			num;

	y = 0;
	while (val[y])
	{
		if (!ft_str_is_num(val[y]))
			return (0);
		num = ft_atoi(val[y]);
		if ((x == 0 && num != 1) || (x == ((*env).map_h - 1) && num != 1)
			|| num < 0 || num > 1)
			return (0);
		(*env).map[x][y] = num;
		y++;
	}
	if (y != (*env).map_w || !ft_atoi(val[0]) || !ft_atoi(val[--y]))
		return (0);
	return (1);
}

static int		ft_read_file(int fd, t_env *env)
{
	char		*line;
	char		**val;
	int			x;

	x = 0;
	while (get_next_line(fd, &line))
	{
		val = ft_strsplit(line, ' ');
		if (ft_read_width(val, x, env) == 0)
		{
			free(line);
			return (0);
		}
		ft_free_sstr(&val);
		free(line);
		x++;
	}
	if (x != (*env).map_h ||
			(*env).map[(int)(*env).player.posx][(int)(*env).player.posy] != 0)
		return (0);
	return (1);
}

int				ft_read(char *file, t_env *env)
{
	int			fd;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (map_info(fd, env) == 0 || (ft_read_file(fd, env)) == 0)
		{
			close(fd);
			map_error(&env);
		}
		close(fd);
		msg();
		return (1);
	}
	close(fd);
	map_error(&env);
	return (0);
}

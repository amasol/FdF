/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:12:54 by amasol            #+#    #+#             */
/*   Updated: 2018/10/18 13:12:55 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void			start_mlx(t_mlx *mlx, t_glob *glob)
{
	glob->mlx = mlx;
	mlx->go = mlx_init();
	mlx->window = mlx_new_window(mlx->go, WINDOW_X, WINDOW_Y, "FdF");
	mlx_hook(mlx->window, 2, (1L << 0), key_param, (void *)&glob);
	initialize(&glob);
	payment(&glob, mlx);
	draw_help(glob->mlx);
	mlx_loop(mlx->go);
}

static int		check_error(char **argv)
{
	int		fd;

	if ((fd = open(argv[1], O_DIRECTORY)) > 0)
	{
		write(1, "Error validation\n", 6);
		return (-1);
	}
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		write(1, "Error validation\n", 6);
	return (fd);
}

int				main(int argc, char **argv)
{
	t_glob	glob;
	t_map	*map;
	t_mlx	mlx;
	int		fd;

	map = NULL;
	if ((fd = check_error(argv)) < 0)
		return (0);
	if (argc != 2)
	{
		write(1, "usage: fdf map_name\n", 20);
		return (-1);
	}

	save_map(&glob, &map, fd);

	save_matrix(map, &glob);
	start_mlx(&mlx, &glob);

	system("leaks fdf");
	return (0);
}

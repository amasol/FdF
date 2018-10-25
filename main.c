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

//void				file_free(t_point **alst, t_glob **glob)
//{
//	int		x;
//
//	x = 0;
//	if (!alst[x])
//		return ;
//	while(x < (*glob)->len.x)
//	{
//		free(alst[x]);
//		x++;
//	}
//}

void				file_free(t_point **alst, t_glob *glob)
{
	int		x;

	x = 0;
	if (!alst[x])
		return ;
	while(x < glob->len.x)
	{
		free(alst[x]);
		x++;
	}
}


static void			start_mlx(t_mlx *mlx, t_glob *glob)
{
	glob->mlx = mlx;
	mlx->go = mlx_init();
	mlx->window = mlx_new_window(mlx->go, WINDOW_X, WINDOW_Y, "paracha");
	mlx_hook(mlx->window, 2, (1L << 0), esc_extt, (void *)&glob);
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
//int				main(void)
{
	t_glob	glob;
	t_map	*map;
	t_mlx	mlx;
	int fd;

	map = NULL;

	fd = open("test_maps/pyramide.fdf", O_RDONLY);
//	if ((fd = check_error(argv)) < 0)
//		return (0);
//	if (argc != 2)
//	{
//		write(1, "usage: fdf map_name\n", 20);
//		return (-1);
//	}
	save_map(&glob, &map, fd);
	save_matrix(map, &glob);
//	start_mlx(&mlx, &glob);

//	file_free(glob.len.matrix, &glob);

//	system("leaks fdf");
	return (0);
}

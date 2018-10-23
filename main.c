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
//	int y = -1;
//	int x;
	mlx->go = mlx_init();
	mlx->window = mlx_new_window(mlx->go, WINDOW_X, WINDOW_Y, "paracha");
	payment(&glob, mlx);



//	mlx_pixel_put(mlx->go, mlx->window, 250, 250, 0xBA55D3);
//	mlx_pixel_put(mlx->go, mlx->window, glob->len.matrix[y], glob->len.x, 0xBA55D3);

//	while (++y < glob->len.y)
//	{
//		x = -1;
//		while (++x < glob->len.x)
//		{
//			c
//		}
//	}




//	mlx_key_hook(mlx->go, test_funk, (void *)0);
//	mlx->img = mlx_new_image(mlx->go, WINDOW_X, WINDOW_Y);
//	mlx->img_inform = mlx_get_data_addr(mlx->img, &(glob->bits_pixel),
//			&(glob->size_line), &(glob->endian));
}

int				main(void)
{
	t_glob	glob;
	t_map	*map;
	t_mlx	mlx;

	map = NULL;
	save_map(&glob, &map);
	save_matrix(map, &glob);
	start_mlx(&mlx, &glob);
//	system("leaks fdf");

	return (0);
}

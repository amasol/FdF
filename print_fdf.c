/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:22:53 by amasol            #+#    #+#             */
/*   Updated: 2018/10/21 17:22:55 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//  как правильно присвоить кнопку для выведение +- нашей картинки !

int				esc_extt(int key, t_glob **glob)
{
    if (key == 53)
		exit(1);
	if (key == 69)
		(*glob)->zoom = 5;
	if (key == 78)
		(*glob)->zoom = 5;
    return (1);
}


int				payment(t_glob **glob, t_mlx *mlx)
{
	t_glob t0;
	t0.y = 0;
	(*glob)->zoom = 0;

	while (t0.y < (*glob)->len.y)
	{
		t0.x = 0;
		while (t0.x < (*glob)->len.x)
		{
			if (t0.x + 1 < (*glob)->len.x)
            {
				t0.xx = t0.x * 20;
				t0.yy = t0.y * 20;
				t0.x_next = (t0.x + 1) * 20;
				t0.y_next = t0.y * 20;
				t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
//				t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
				line_output(&t0, 0xFF00FF, mlx);
			}
			if (t0.y + 1 < (*glob)->len.y)
			{
				t0.xx = t0.x * 20;
				t0.yy = t0.y * 20;
				t0.x_next = t0.x * 20;
				t0.y_next = (t0.y + 1) * 20;
//				t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
				line_output(&t0, 0xFF00FF, mlx);
			}
			t0.x++;
		}
		t0.y++;
	}
	mlx_key_hook(mlx->window, esc_extt, (void *)glob);
//	mlx_key_hook(mlx->window, esc_extt, &glob);
//	printf("%d\n", (*glob)->zoom);
	mlx_loop(mlx->go);
	return (0);
}

























/*

int				payment(t_glob **glob, t_mlx *mlx)
{
	t_glob t0;
	int rast;
	rast = 0;

	t0.y = 0;
	(*glob)->zoom = 0;



	while (t0.y < (*glob)->len.y)
	{
		t0.x = 0;
		while (t0.x < (*glob)->len.x)
		{
			if (t0.x + 1 < (*glob)->len.x)
			{
				t0.xx = t0.x - t0.y;
				t0.yy = (*glob)->len.matrix[t0.y][t0.x].z * -2 + t0.x + t0.y;
				t0.x_ttt = (t0.xx - t0.yy);

				t0.x_next = ((t0.xx + rast) - t0.yy);
				t0.y_next = ((*glob)->len.matrix[t0.y][t0.x + 1].z * -2 + t0.xx + rast + t0.yy);

				line_output(&t0, 0xFF00FF, mlx);
				t0.xx += rast;
			}
			t0.yy += rast;
			if (t0.y + 1 < (*glob)->len.y)
			{
				t0.xx = t0.x;
				t0.yy = t0.y;
				t0.x_ttt = t0.xx - t0.yy;
				t0.x_next = t0.x * 20;
				t0.x_next = t0.xx - (t0.yy + 5);
				t0.y_next = (t0.y + 1) * 20;
				t0.y_next = ((*glob)->len.matrix[t0.y + 1][t0.x].z * -2 + t0.xx + 5 + t0.yy);

				t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
				t0.z = (*glob)->len.matrix[t0.y][t0.x].z * -5 + t0.xx + t0.yy;
				line_output(&t0, 0xFF00FF, mlx);
			}
			t0.x++;
		}
		t0.y++;
	}
	mlx_key_hook(mlx->window, esc_extt, (void *)glob);
//	mlx_key_hook(mlx->window, esc_extt, &glob);
	mlx_loop(mlx->go);
	return (0);
}

*/












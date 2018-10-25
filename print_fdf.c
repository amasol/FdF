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
/*
void	draw_help(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 10;
	y = 1;
	mlx_string_put(mlx->go, mlx->window, x, (y++ * 20), 0xFFFFFF,
				   "Use arrows to move left(<-), right(->), up(^) and down(V)");
	mlx_string_put(mlx->go, mlx->window, x, (y++ * 20), 0xFFFFFF,
				   "Use 4, 6, 8, 2 to rotate model");
	mlx_string_put(mlx->go, mlx->window, x, (y++ * 20), 0xFFFFFF,
				   "Use +, - to increase and decrease model");
}



int				esc_extt(int key, t_glob **glob)
{
    if (key == 53)
	{
//    	file_free((*glob)->len.matrix, glob);
		system("leaks fdf");
		exit(1);
	}
	if (key == 69)
	{
		(*glob)->scale += 2;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	if (key == 78 && (*glob)->scale > 0)
	{
		(*glob)->scale -= 2;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 91)
	{
		(*glob)->rx += 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 84)
	{
		(*glob)->rx -= 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 86)
	{
		(*glob)->ry += 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 88)
	{
		(*glob)->ry -= 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 124)
	{
		(*glob)->start_x += 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 123)
	{
		(*glob)->start_x -= 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 125)
	{
		(*glob)->start_y += 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 126)
	{
		(*glob)->start_y -= 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
    return (1);
}

void	initialize(t_glob **glob)
{
	(*glob)->y = 0;
	(*glob)->start_x = 800 / 2;
	(*glob)->start_y = 500 / 2;
	(*glob)->scale = 20;
	(*glob)->rx = 0.785398;
	(*glob)->ry = 0.785398;
}

void			payment(t_glob **glob, t_mlx *mlx)
{
	t_glob t0;
	int z0;

	t0 = **glob;
	while (t0.y < (*glob)->len.y)
	{
		t0.x = 0;
		while (t0.x < (*glob)->len.x)
		{
			if (t0.x + 1 < (*glob)->len.x)
            {
            	t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
				t0.z_next = (*glob)->len.matrix[t0.y][t0.x + 1].z;


				t0.yy = t0.y * t0.scale * cos(t0.rx) - t0.z * t0.scale / 10 * sin(t0.rx);
				z0 = -t0.z * t0.scale / 10 * cos(t0.rx) - t0.y * t0.scale * sin(t0.rx);
				t0.xx = t0.x * t0.scale  * cos(-t0.ry) - z0 * sin(-t0.ry);
				t0.y_next = t0.y * t0.scale * cos(t0.rx) - t0.z_next * t0.scale / 10 * sin(t0.rx);
				z0 = -t0.z_next * t0.scale / 10 * cos(t0.rx) - t0.y * t0.scale * sin(t0.rx);
				t0.x_next = (t0.x + 1) * t0.scale  * cos(-t0.ry) - z0 * sin(-t0.ry);
				line_output(&t0, 0xAFF000, mlx);
			}
			if (t0.y + 1 < (*glob)->len.y)
			{
				t0.z = (*glob)->len.matrix[t0.y][t0.x].z;
				t0.z_next = (*glob)->len.matrix[t0.y + 1][t0.x].z;

				t0.yy = t0.y * t0.scale * cos(t0.rx) - t0.z * t0.scale / 10 * sin(t0.rx);
				z0 = -t0.z * t0.scale / 10 * cos(t0.rx) - t0.y * t0.scale * sin(t0.rx);
				t0.xx = t0.x * t0.scale  * cos(-t0.ry) - z0 * sin(-t0.ry);
				t0.y_next = (t0.y + 1) * t0.scale * cos(t0.rx) - t0.z_next * t0.scale / 10 * sin(t0.rx);
				z0 = -t0.z_next * t0.scale / 10 * cos(t0.rx) - (t0.y + 1) * t0.scale * sin(t0.rx);
				t0.x_next = t0.x * t0.scale  * cos(-t0.ry) - z0 * sin(-t0.ry);
				line_output(&t0, 0xAFF000, mlx);
			}
			t0.x++;
		}
		t0.y++;
	}
}







*/











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

int             esc_extt(int key)
{
    if (key == 53)
        exit(1);
    return (1);
}

void			initialization(t_glob *t0);
{

}

//void            line_output(int x0, int y0, int x1, int y1, int color, t_mlx *mlx, int *z)
void			line_output(t_glob *t0, int color, t_mlx *mlx)
{
	int y;
	int i = 1;
	int x = 0;
    {
    
		int dx = abs(x1 - x0);
		int dy = abs(y1 - y0);
		int sx = x1 >= x0 ? 1 : -1;
		int sy = y1 >= y0 ? 1 : -1;
        if (dy <= dx)
        {
            int d = (dy << 1) - dx;
            int d1 = dy << 1;
            int d2 = (dy - dx) << 1;
            int tmp_z4 = *z;
            int tmp_x4 = x0;
            int tmp_y4 = y0;

            modify_coords(&tmp_x4, &tmp_y4, &tmp_z4);
            mlx_pixel_put(mlx->go, mlx->window, tmp_x4, tmp_y4, color);
			y = y0;
			x = x0 + sx;
			while (i < dx)
			{
				if (d > 0)
				{
					d += d2;
					y += sy;
				}
				else
                {
					int tmp_z = *z;
					int tmp_x = x;
					int tmp_y = y;
					
					modify_coords(&tmp_x, &tmp_y, &tmp_z);
					mlx_pixel_put(mlx->go, mlx->window, tmp_x, tmp_y, 0xffffff);
                }
				x += + sx;
                i++;
            }
        }
        else
        {
            int d = (dx << 1) - dy;
            int d1 = dx << 1;
            int d2 = (dx - dy) << 1;
            int tmp_z3 = *z;
            int tmp_x3 = x0;
            int tmp_y3 = y0;
            
            modify_coords(&tmp_x3, &tmp_y3, &tmp_z3);
			mlx_pixel_put(mlx->go, mlx->window, tmp_x3, tmp_y3, color);
			x = x0;
			y = y0 + sy;
			while (i < dy)
			{
				if (d > 0)
				{
					d += d2;
					x += sx;
				}
				else
				{
					d += d1;
					int tmp_z1 = *z;
					int tmp_x1 = x;
					int tmp_y1 = y;

					modify_coords(&tmp_x1, &tmp_y1, &tmp_z1);
					mlx_pixel_put(mlx->go, mlx->window, tmp_x1, tmp_y1, 0xffffff);
				}
				y += sy;
				i++;
			}
		}
	}
}




int				payment(t_glob **glob, t_mlx *mlx)
{
//	t_glob t1;
	t_glob t0;
	
	t0.y = 0;
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
//					line_output(t0.x * 20, t0.y * 20, (t0.x + 1) * 20, t0.y * 20, 0x00ffffff, mlx,
//							&(*glob)->len.matrix[t0.y][t0.x].z);
				line_output(t0, 0x00ffffff, mlx);
			}
			if (t0.y + 1 < (*glob)->len.y)
			{
 					line_output(t0.x * 20, t0.y * 20, t0.x * 20, (t0.y + 1) * 20, 0x00ffffff, mlx,
 							&(*glob)->len.matrix[t0.y][t0.x].z);
			}
			t0.x++;
		}
		t0.y++;
	}
	mlx_key_hook(mlx->window, esc_extt, (void *)0);
	mlx_loop(mlx->go);
	return (0);
}

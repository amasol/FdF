
#include "fdf.h"

static int			ft_abs(int x)
{
	return (x > 0 ? x : -(x));
}

static int			ft_max(int length_x, int length_y)
{
	if (length_x >= length_y)
		return (length_x);
	return (length_y);
}


static void			change(t_glob **t0)
{
	(*t0)->dx = ((*t0)->x_next - (*t0)->xx >= 0 ? 1 : -1);
	(*t0)->dy = ((*t0)->y_next - (*t0)->yy >= 0 ? 1 : -1);

	(*t0)->lx = ft_abs((*t0)->x_next - (*t0)->xx);
	(*t0)->ly = ft_abs((*t0)->y_next - (*t0)->yy);

	(*t0)->ll = ft_max((*t0)->lx, (*t0)->ly);
}

static void			line_output_help_two(t_glob **t0, int color, t_mlx **mlx)
{
	if (mlx)
	{
		(*t0)->tmp_x1 = (*t0)->xx;
		(*t0)->tmp_y1 = (*t0)->yy;
		(*t0)->tmp_d1 = - (*t0)->ly;

		(*t0)->ll++;
		while((*t0)->ll != 0)
		{
//			modify_coords(&(*t0)->tmp_x1, &(*t0)->tmp_y1, &(*t0)->z);
			mlx_pixel_put((*mlx)->go, (*mlx)->window, (*t0)->tmp_x1 + (800 / 2),
				(*t0)->tmp_y1 + (500 / 2), color);
			(*t0)->tmp_y1 += (*t0)->dy;
			(*t0)->tmp_d1 += 2 * (*t0)->lx;
			if ((*t0)->tmp_d1 > 0)
			{
				(*t0)->tmp_d1 -= 2 * (*t0)->ly;
				(*t0)->tmp_x1 += (*t0)->dx;
			}
			(*t0)->ll--;
		}
	}
}

static void			line_output_help(t_glob **t0, int color, t_mlx **mlx)
{
	if ((*t0)->ly <= (*t0)->lx)
	{
		(*t0)->tmp_x = (*t0)->xx;
		(*t0)->tmp_y = (*t0)->yy;
		(*t0)->tmp_d = -(*t0)->lx;

		(*t0)->ll++;
		while((*t0)->ll != 0)
		{
//			modify_coords(&(*t0)->tmp_x, &(*t0)->tmp_y, &(*t0)->z);
			mlx_pixel_put((*mlx)->go, (*mlx)->window, (*t0)->tmp_x + (800 / 2),
						  (*t0)->tmp_y + (500 / 2), color);
			(*t0)->tmp_x += (*t0)->dx;
			(*t0)->tmp_d += 2 * (*t0)->ly;
			if ((*t0)->tmp_d > 0)
			{
				(*t0)->tmp_d -= 2 * (*t0)->lx;
				(*t0)->tmp_y += (*t0)->dy;
			}
			(*t0)->ll--;
		}
	}
}

void			line_output(t_glob *t0, int color, t_mlx *mlx)
{
	if (mlx)
	{
		change(&t0);

//		modify_coords(&t0->xx, &t0->yy, &t0->z);
		if (t0->ll == 0)
			mlx_pixel_put(mlx->go, mlx->window, t0->xx + (800 / 2), t0->yy + (500 / 2), color);
		if (t0->ly <= t0->lx)
			line_output_help(&t0, color, &mlx);
		else
			line_output_help_two(&t0, color, &mlx);
	}
}
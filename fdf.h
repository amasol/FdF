/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:31:32 by amasol            #+#    #+#             */
/*   Updated: 2018/10/26 16:31:34 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "./libft/libft.h"
# include <math.h>

# define WINDOW_X 1200
# define WINDOW_Y 720

typedef struct		s_mlx
{
	void			*go;
	void			*window;

}					t_mlx;

typedef struct		s_map
{
	char			**map_save;
	struct s_map	*next;
}					t_map;

typedef struct		s_point
{
	int				z;
}					t_point;

typedef struct		s_len
{
	int				x;
	int				y;
	t_point			**matrix;
}					t_len;

typedef	struct		s_glob
{
	int				x;
	int				y;

	int				z;
	int				z_next;
	int				xx;
	int				yy;
	int				x_next;
	int				y_next;
	float			rx;
	float			ry;
	int				dx;
	int				dy;
	int				lx;
	int				ly;
	int				ll;

	int				tmp_x;
	int				tmp_y;

	int				tmp_d;
	int				tmp_d1;

	int				tmp_x1;
	int				tmp_y1;

	int				start_x;
	int				start_y;
	int				scale;

	t_len			len;

	t_mlx			*mlx;
}					t_glob;

int					main(int argc, char **argv);
int					ft_s(int x);
int					ft_size_list(t_map *lst);
int					len_x(char **str);
int					save_matrix(t_map *map, t_glob *glob);
void				error(void);
void				add_list(t_map **map, char **str);
void				save_map(t_glob *glob, t_map **map, int fd);
void				payment(t_glob **glob, t_mlx *mlx);
void				initialize(t_glob **glob);
void				line_output(t_glob *t0, int color, t_mlx *mlx);
void				draw_help(t_mlx *mlx);
int					key_param(int key, t_glob **glob);

#endif

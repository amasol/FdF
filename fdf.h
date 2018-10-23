/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:12:26 by amasol            #+#    #+#             */
/*   Updated: 2018/10/18 13:12:28 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>// библиотека для згачегтй double
# define WINDOW_X 1024
# define WINDOW_Y 768

typedef struct	s_mlx
{
	void		*go;
	void		*img;
	char		*img_inform;
	void		*window;

}				t_mlx;

typedef	struct		s_map
{
	char			**map_save;
	struct s_map	*next;
}					t_map;

typedef	struct		s_point
{
	int				z;
	int				color;
}					t_point;

typedef	struct		s_len
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
	int				xx;
	int				yy;
	int				x_next;
	int				y_next;
	
	
	int				s_r;
	int				centering_x;
	int				centering_y;
	int				endian;
	int				bits_pixel;
	int				size_line;
	t_len			len;
}					t_glob;


int					main(void);


int					ft_size_list(t_map *lst);
int					len_x(char **str);
int					save_matrix(t_map *map, t_glob *glob);
void				error(void);
void				add_list(t_map **map, char **str);
void				save_map(t_glob *glob, t_map **map);
int					payment(t_glob **glob, t_mlx *mlx);
//void                line_output(int x0, int y0, int x1, int y1, int color, t_mlx *mlx, int *z);
void				line_output(t_glob *t0, int color, t_mlx *mlx);
void                modify_coords(int *x, int *y, int *z);
int                 esc_extt(int key);

#endif

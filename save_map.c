/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:39:28 by amasol            #+#    #+#             */
/*   Updated: 2018/10/19 12:39:30 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			add_list(t_map **map, char **str)
{
	t_map	*tmp;
	t_map	*tmp2;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->map_save = str;
	tmp->next = NULL;
	if (*map == NULL)
		*map = tmp;
	else
	{
		tmp2 = *map;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}

int				len_x(char **str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

static int		alloc_matrix(t_glob *glob)
{
	int		i;

	if (!(glob->len.matrix = (t_point **)malloc(glob->len.y * sizeof(t_point *))))
		return (0);
	i = -1;
	while (++i < glob->len.x)
		if (!(glob->len.matrix[i] = (t_point *)malloc(glob->len.x * sizeof(t_point))))
			return (0);
	return (1);
}

int				save_matrix(t_map *map, t_glob *glob)
{
	int		heig;
	int		wid;
	t_map	*cur;

	cur = map;
	glob->len.y = ft_size_list(cur);
	alloc_matrix(glob);
	heig = 0;
	while (glob->len.y > heig)
	{
		wid = 0;
		while (glob->len.x > wid)
		{
			glob->len.matrix[heig][wid].z = (int)ft_atoi(cur->map_save[wid]);
			wid++;
		}
		heig++;
		cur = cur->next;
	}
	return (0);
}

void			save_map(t_glob *glob, t_map **map)
{
	char 	**str;
	char	*line;
	int		fd;

	fd = open("test_maps/42.fdf", O_RDONLY);
	glob->len.x = -1;
	if (get_next_line(fd, &(line)) > 0)
	{
		str = ft_strsplit(line, ' ');
		free(line);
		add_list(&(*map), str);
		glob->len.x = len_x(str);
	}
	if (glob->len.x <= 0)
		error();
	while (get_next_line(fd, &(line)) > 0)
	{
		str = ft_strsplit(line, ' ');
		free(line);
		add_list(&(*map), str);
	}
	close(fd);
}
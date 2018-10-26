/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:22:38 by amasol            #+#    #+#             */
/*   Updated: 2018/10/26 11:22:40 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_s(int x)
{
	return (x > 0 ? x : -(x));
}

static void		key_param_help(int *key, t_glob **glob)
{
	if ((*key) == 91)
	{
		(*glob)->rx += 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if ((*key) == 84)
	{
		(*glob)->rx -= 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if ((*key) == 86)
	{
		(*glob)->ry += 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
}

static void		key_param_help_two(int *key, t_glob **glob)
{
	if ((*key) == 88)
	{
		(*glob)->ry -= 0.034906585;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if ((*key) == 124)
	{
		(*glob)->start_x += 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if ((*key) == 123)
	{
		(*glob)->start_x -= 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
}

static void		key_param_help_three(int *key, t_glob **glob)
{
	if ((*key) == 125)
	{
		(*glob)->start_y += 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if ((*key) == 126)
	{
		(*glob)->start_y -= 15;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
}

int				key_param(int key, t_glob **glob)
{
	if (key == 53)
		exit(1);
	else if (key == 69)
	{
		(*glob)->scale += 2;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	else if (key == 78 && (*glob)->scale > 0)
	{
		(*glob)->scale -= 2;
		mlx_clear_window((*glob)->mlx->go, (*glob)->mlx->window);
		payment(glob, (*glob)->mlx);
		draw_help((*glob)->mlx);
	}
	key_param_help(&key, glob);
	key_param_help_two(&key, glob);
	key_param_help_three(&key, glob);
	return (1);
}

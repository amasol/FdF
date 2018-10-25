/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mogify_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:03:26 by amasol            #+#    #+#             */
/*   Updated: 2018/10/22 19:03:28 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void        modify_coords(int *x, int *y, int *z)
{
    static int cnt = 0;
//    if (cnt < 100)
//        fprintf(stderr, "before:%d %d %d\n", *x, *y, *z);

	double alpha = (45  * 3.14) / 180;
	double beta = (45  * 3.14) / 180;
	double gama= (45  * 3.14) / 180;
	int tmp_x;
	int tmp_y;
	int tmp_z;
	
	
	tmp_x= *x;
	tmp_y= *y * cos(alpha) + *z * sin(alpha);
	tmp_z= -tmp_y * sin(alpha) + *z *cos(alpha);

//	tmp_x = *x * cos(beta) + *z * sin(beta);
//	tmp_y = *y;
//	tmp_z = -*x *sin(beta) + *z * cos(beta);

//	tmp_x = *x *cos(gama) - *y * sin(gama);
//	tmp_y = *x *sin(gama) + *y * cos(gama);
//	tmp_z = *z;
	
//    x'=x*cos(b)+z*sin(b);
//    y'=y;
//    z'=-x*sin(b)+z*cos(b)
//
//    x'=x*cos(g)-y*sin(g);
//    y'=x*sin(g)+y*cos(g);
//    z'=z;

	*x = tmp_x;
	*y = tmp_y;
	*z = tmp_z;

//    if (cnt < 100)
//        fprintf(stderr, "after:%d %d %d\n", *x, *y, *z);
    cnt++;
}

/*
void	get2d(t_3d_position p, t_view *v, int *x, int *y)
{
	int		x0;
	int		y0;

	y0 = p.y * cos(v->rx) + p.z * sin(v->rx);
	p.z = p.z * cos(v->rx) - p.y * sin(v->rx);
	x0 = p.x * cos(v->ry) - p.z * sin(v->ry);
	*x = x0 * cos(v->rz) + y0 * sin(v->rz) + v->cx;
	*y = y0 * cos(v->rz) - x0 * sin(v->rz) + v->cy;
}*/
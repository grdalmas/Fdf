/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_z_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:39:26 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/24 14:01:43 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		z_origin(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
			e->map[y][x].z = e->map[y][x].zorigin;
	}
	print_fdf(e);
}

void		z_modif(t_env *e, int key)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
		{
			if (key == KEY_PAD_5)
				e->map[y][x].z *= 1.1;
			else if (key == KEY_PAD_8)
				e->map[y][x].z /= 1.1;
		}
	}
	new_image(e);
	print_bresenham_to_image(e);
}

void		z_max_to_min(t_env *e)
{
	if (e->min_z < 0)
		e->dist_z = e->max_z - e->min_z;
	else if (e->min_z >= 0)
		e->dist_z = e->max_z + e->min_z;
	color_put(e);
}

void		z_max_n_min(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
		{
			if (e->map[y][x].z > e->max_z)
				e->max_z = e->map[y][x].z;
			else if (e->map[y][x].z < e->min_z)
				e->min_z = e->map[y][x].z;
		}
	}
	z_max_to_min(e);
}

int			is_isometric(t_env *e, int x, int y, char c)
{
	int		xi;
	int		yi;

	yi = y + 1;
	xi = x + 1;
	if (x < e->max_x && xi < e->max_x && c == 'x' && x >= 0)
	{
		e->pt1.x = e->map[y][x].xm - ((e->map[y][x].ym / 1.5) * e->isometric);
		e->pt1.y = e->map[y][x].ym - e->map[y][x].z;
		e->pt2.x = e->map[y][xi].xm - ((e->map[y][xi].ym / 1.5) * e->isometric);
		e->pt2.y = e->map[y][xi].ym - e->map[y][xi].z;
		return (1);
	}
	if (y < e->max_y && yi < e->max_y && c == 'y' && y >= 0)
	{
		e->pt1.x = e->map[y][x].xm - ((e->map[y][x].ym / 1.5) * e->isometric);
		e->pt1.y = e->map[y][x].ym - e->map[y][x].z;
		e->pt2.x = e->map[yi][x].xm - ((e->map[yi][x].ym / 1.5) * e->isometric);
		e->pt2.y = e->map[yi][x].ym - e->map[yi][x].z;
		return (1);
	}
	return (0);
}

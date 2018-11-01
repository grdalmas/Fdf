/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:34:01 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/24 14:01:02 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		while_print(t_env *e, int x, int y)
{
	if ((is_isometric(e, x, y, 'x')) > 0)
		print_x(e, x, y);
	if ((is_isometric(e, x, y, 'y')) > 0)
		print_y(e, x, y);
}

void		print_bresenham_to_image(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
			while_print(e, x, y);
	}
	size_recovery(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->mlx_img, 0, 0);
	info_panel(e);
	mlx_destroy_image(e->mlx_ptr, e->mlx_img);
}

void		draw_vertical(t_env *e, int color)
{
	e->bresenham.cumul = e->bresenham.dx / 2;
	e->bresenham.i = 0;
	while (++e->bresenham.i <= e->bresenham.dx)
	{
		e->bresenham.xb += e->bresenham.xinc;
		e->bresenham.cumul += e->bresenham.dy;
		if (e->bresenham.cumul >= e->bresenham.dx)
		{
			e->bresenham.cumul -= e->bresenham.dx;
			e->bresenham.yb += e->bresenham.yinc;
		}
		ft_put_pixel_image(e, e->bresenham.yb, e->bresenham.xb, color);
	}
}

void		draw_horizontal(t_env *e, int color)
{
	e->bresenham.cumul = e->bresenham.dy / 2;
	e->bresenham.i = 0;
	while (++e->bresenham.i <= e->bresenham.dy)
	{
		e->bresenham.yb += e->bresenham.yinc;
		e->bresenham.cumul += e->bresenham.dx;
		if (e->bresenham.cumul >= e->bresenham.dy)
		{
			e->bresenham.cumul -= e->bresenham.dy;
			e->bresenham.xb += e->bresenham.xinc;
		}
		ft_put_pixel_image(e, e->bresenham.yb, e->bresenham.xb, color);
	}
}

void		draw_line(t_env *e, int color)
{
	e->bresenham.xb = e->pt1.x;
	e->bresenham.yb = e->pt1.y;
	e->bresenham.dx = e->pt2.x - e->pt1.x;
	e->bresenham.dy = e->pt2.y - e->pt1.y;
	e->bresenham.xinc = (e->bresenham.dx > 0) ? 1 : -1;
	e->bresenham.yinc = (e->bresenham.dy > 0) ? 1 : -1;
	e->bresenham.dx = abs(e->bresenham.dx);
	e->bresenham.dy = abs(e->bresenham.dy);
	ft_put_pixel_image(e, e->bresenham.yb, e->bresenham.xb, color);
	if (e->bresenham.dx > e->bresenham.dy)
		draw_vertical(e, color);
	else
		draw_horizontal(e, color);
}

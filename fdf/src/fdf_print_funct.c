/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:39:28 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/24 13:59:16 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		put_background(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_put_pixel_image(e, y, x, BACKGROUND);
		}
	}
}

void		print_x(t_env *e, int x, int y)
{
	if (e->map[y][x].z < e->map[y][x + 1].z)
	{
		if (e->mod_z > 0)
			draw_line(e, e->map[y][x + 1].color_map);
		else
			draw_line(e, e->map[y][x].color_map);
	}
	else
	{
		if (e->mod_z > 0)
			draw_line(e, e->map[y][x].color_map);
		else
			draw_line(e, e->map[y][x + 1].color_map);
	}
}

void		print_y(t_env *e, int x, int y)
{
	if (e->map[y][x].z < e->map[y + 1][x].z)
	{
		if (e->mod_z > 0)
			draw_line(e, e->map[y + 1][x].color_map);
		else
			draw_line(e, e->map[y][x].color_map);
	}
	else
	{
		if (e->mod_z > 0)
			draw_line(e, e->map[y][x].color_map);
		else
			draw_line(e, e->map[y + 1][x].color_map);
	}
}

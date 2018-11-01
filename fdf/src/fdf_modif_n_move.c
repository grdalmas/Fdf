/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modif_n_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:02:36 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/24 12:37:54 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move(t_env *e)
{
	e->moving_x = ((e->size_xo - e->size_x) / 2);
	e->moving_y = ((e->size_yo - e->size_y) / 2);
}

void		zoom(t_env *e, int key)
{
	int		x;
	int		y;

	y = -1;
	size_recovery_o(e);
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
		{
			if (key == PLUS)
			{
				e->map[y][x].xm *= 1.1;
				e->map[y][x].ym *= 1.1;
			}
			else
			{
				e->map[y][x].xm /= 1.1;
				e->map[y][x].ym /= 1.1;
			}
		}
	}
	size_recovery(e);
	move(e);
	print_fdf(e);
}

void		size_recovery(t_env *e)
{
	e->size_x = (e->map[0][e->max_x - 1].xm - e->map[0][0].xm);
	e->size_y = (e->map[e->max_y - 1][0].ym - e->map[0][0].ym);
}

void		size_recovery_o(t_env *e)
{
	e->size_xo = (e->map[0][e->max_x - 1].xm - e->map[0][0].xm);
	e->size_yo = (e->map[e->max_y - 1][0].ym - e->map[0][0].ym);
}

void		modif_fdf(t_env *e, int key)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
		{
			if (key == LEFT)
				e->map[y][x].xm -= 20;
			else if (key == RIGHT)
				e->map[y][x].xm += 20;
			else if (key == DOWN)
				e->map[y][x].ym += 20;
			else if (key == UP)
				e->map[y][x].ym -= 20;
		}
	}
	new_image(e);
	print_bresenham_to_image(e);
}

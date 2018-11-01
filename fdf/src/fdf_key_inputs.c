/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:14:37 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/25 13:32:10 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	origin(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
		{
			e->map[y][x].xm = x;
			e->map[y][x].ym = y;
			e->map[y][x].z = e->map[y][x].zorigin;
		}
	}
	print_fdf(e);
}

void	z_reverse(t_env *e)
{
	int		x;
	int		y;

	e->mod_z *= -1;
	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
			e->map[y][x].z *= -1;
	}
	print_fdf(e);
}

void	info(t_env *e)
{
	e->ipanel *= -1;
	print_fdf(e);
}

void	iso_n_background(t_env *e, int key)
{
	if (key == KEY_R)
	{
		e->isometric *= -1;
		print_fdf(e);
	}
	if (key == KEY_B)
	{
		e->bgrnd *= -1;
		print_fdf(e);
	}
}

int		press_key(int key, t_env *e)
{
	if (key == ESC)
		ft_error("See you space clodo");
	if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		modif_fdf(e, key);
	if (key == MINUS || key == PLUS)
		zoom(e, key);
	if (key == KEY_PAD_5 || key == KEY_PAD_8)
		z_modif(e, key);
	if (key == KEY_R || key == KEY_B)
		iso_n_background(e, key);
	if (key == KEY_I)
		info(e);
	if (key == KEY_X)
		z_reverse(e);
	if (key == KEY_O)
		origin(e);
	if (key == KEY_Z)
		z_origin(e);
	return (0);
}

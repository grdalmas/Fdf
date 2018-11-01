/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:51:04 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/25 16:58:54 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				locate_colors(t_env *e, int z)
{
	double		d;

	d = e->dist_z / 10;
	if (z >= e->min_z && z < (e->min_z + (d * 1)))
		return (BLUE_W);
	else if ((z >= e->min_z + (d)) && z < (e->min_z + (d * 2)))
		return (YELLOW);
	else if ((z >= e->min_z + (d * 2)) && z < (e->min_z + (d * 3)))
		return (PALE_GREEN);
	else if ((z >= e->min_z + (d * 3)) && z < (e->min_z + (d * 4)))
		return (PALE_GREEN);
	else if ((z >= e->min_z + (d * 4)) && z < (e->min_z + (d * 5)))
		return (GREEN);
	else if ((z >= e->min_z + (d * 5)) && z < (e->min_z + (d * 6)))
		return (GREEN);
	else if ((z >= e->min_z + (d * 6)) && z < (e->min_z + (d * 7)))
		return (BROWN);
	else if ((z >= e->min_z + (d * 7)) && z < (e->min_z + (d * 8)))
		return (BROWN);
	else if ((z >= e->min_z + (d * 8)) && z < (e->min_z + (d * 9)))
		return (WHITE);
	else if (z >= (e->min_z + (d * 9)) && z <= e->dist_z)
		return (WHITE);
	return (WHITE);
}

void			color_put(t_env *e)
{
	int			y;
	int			x;

	y = -1;
	while (++y < e->max_y)
	{
		x = -1;
		while (++x < e->max_x)
			e->map[y][x].color_map = (locate_colors(e, e->map[y][x].z));
	}
}

void			info_panel2(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 100, WHITE, e->string);
	e->string = "  *     Press 8 to lower height     *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 120, WHITE, e->string);
	e->string = "  *     Press X to reverse z        *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 140, WHITE, e->string);
	e->string = "  * Press Z to go back to origin z  *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 160, WHITE, e->string);
	e->string = "  *     Press O to reset origin     *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 180, WHITE, e->string);
	e->string = "  *    Press <- -> ^ or v to move   *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 200, WHITE, e->string);
	e->string = "  *     Press R to change iso       *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 220, WHITE, e->string);
	e->string = "  *       Press ESC to quit         *";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 240, WHITE, e->string);
	e->string = "  ***********************************";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 260, WHITE, e->string);
}

void			info_panel(t_env *e)
{
	e->string = "Information Panel : I";
	mlx_string_put(e->mlx_ptr, e->win_ptr, 1590, 5, WHITE, e->string);
	if (e->ipanel > 0)
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 1590, 5, WHITE, e->string);
		e->string = "**********************************";
		mlx_string_put(e->mlx_ptr, e->win_ptr, 1590, 25, WHITE, e->string);
		e->string = "  *     Press (+) to zoom in        *";
		mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 40, WHITE, e->string);
		e->string = "  *     Press (-) to zoom out       *";
		mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 60, WHITE, e->string);
		e->string = "  *  Press B for background change  *";
		mlx_string_put(e->mlx_ptr, e->win_ptr, 1565, 80, WHITE, e->string);
		e->string = "  *    Press 5 to augment height    *";
		info_panel2(e);
	}
}

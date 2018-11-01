/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:11:04 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/25 15:50:50 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	new_image(t_env *e)
{
	e->mlx_img = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->mlx_img, &e->bpp, &e->s_l, &e->endian);
	if (e->data == NULL)
		ft_error("Data issue");
	e->bpp /= 8;
	if (e->bgrnd < 0)
		put_background(e);
}

void	ft_put_pixel_image(t_env *e, int y, int x, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(unsigned int*)(e->data + (x * (e->bpp)) + (y * e->s_l)) = color;
}

void	fdf_mlx_init(t_env *e)
{
	e->image = 1;
	if (!(e->mlx_ptr = mlx_init()))
		ft_error("mlx_init failed");
	if (!(e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, NAME)))
		ft_error("Window init failed");
	e->bgrnd = 1;
	e->ipanel = -1;
	e->isometric = -1;
	new_image(e);
}

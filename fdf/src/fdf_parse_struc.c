/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:57:30 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/24 16:39:35 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_atoi_custom(char *str, int n)
{
	int		res;
	int		neg;
	int		i;

	i = 0;
	res = 0;
	neg = 0;
	while ((str[i] <= 8 && str[i] >= 12) || str[i] == 32 || i < n)
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += str[i++] - '0';
		if (str[i] >= '0' && str[i] <= '9')
			res *= 10;
	}
	return (neg ? -res : res);
}

void		check_character(t_env *e, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && str[i + 1] == '-')
			ft_error("Invalid character -");
		if (str[i] == '+' && str[i + 1] == '+')
			ft_error("Invalid character +");
		if (str[i] != '-' && str[i] != '+' && str[i] != ' ' &&
				!(str[i] >= 'A' && str[i] <= 'F') && str[i] != 'x' &&
				!(str[i] >= 'a' && str[i] <= 'f') && str[i] != ',' &&
				!(str[i] >= '0' && str[i] <= '9'))
			ft_error("Invalid character");
	}
	e->check = 1;
}

void		map_2_struct(t_env *e, char *str, int y)
{
	int		i;
	int		x;
	int		locate;

	i = 0;
	x = 0;
	locate = 0;
	check_character(e, str);
	while (str[i] && y < e->max_y)
	{
		while (str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) &&
				locate == 0 && x < e->max_x)
		{
			locate = 1;
			e->map[y][x].z = ft_atoi_custom(str, i);
			e->map[y][x].zorigin = e->map[y][x].z;
			x++;
		}
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9') ||
			str[i] == ',' || str[i] == 'x' || (str[i] >= 'A' && str[i] <= 'F')))
			i++;
		locate = 0;
	}
}

t_map		**ft_create_struct(t_env *e)
{
	int		y;
	int		x;

	if (!(e->map = (t_map **)malloc(sizeof(t_map *) * e->max_y)))
	{
		free(e->map);
		ft_error("Malloc failed for y");
	}
	y = -1;
	while (++y < e->max_y)
	{
		if (!(e->map[y] = (t_map *)malloc(sizeof(t_map) * e->max_x)))
			ft_error("Malloc failed for x");
		x = -1;
		while (++x < e->max_x)
		{
			e->map[y][x].xm = x;
			e->map[y][x].ym = y;
			e->map[y][x].z = 0;
			e->map[y][x].color_map = 0;
		}
	}
	return (e->map);
}

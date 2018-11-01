/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:27:30 by grdalmas          #+#    #+#             */
/*   Updated: 2018/04/25 15:54:44 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			print_fdf(t_env *e)
{
	new_image(e);
	print_bresenham_to_image(e);
}

void			gnl_check(t_env *e, char *line)
{
	free(line);
	if (e->tmp == -1)
		ft_error("Reading failed");
	if (e->max_y == 0 || e->max_x == 0)
		ft_error("Empty file");
	close(e->fd);
}

int				count_character(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = -1;
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

void			read_files(t_env *e, char *str, int y, int i)
{
	char		*line;

	line = NULL;
	while ((e->tmp = get_next_line(e->fd, &line)) > 0)
	{
		if (e->max_y == 0)
			e->max_x = count_character(line);
		if (e->max_y != 0)
			if (e->max_x != count_character(line))
				ft_error("Invalid file");
		e->max_y++;
		free(line);
	}
	gnl_check(e, line);
	e->map = ft_create_struct(e);
	if ((e->fd = open(str, O_RDONLY)) == -1)
		ft_error("No files");
	y = -1;
	i = 0;
	while ((i = get_next_line(e->fd, &line)) > 0 && ++y < e->max_y)
	{
		map_2_struct(e, line, y);
		free(line);
	}
	gnl_check(e, line);
}

int				main(int argc, char **argv)
{
	t_env		e;
	int			i;
	int			y;

	i = 0;
	y = 0;
	e.check = 0;
	e.image = 0;
	e.max_x = 0;
	e.max_y = 0;
	e.mod_z = 1;
	if (argc < 2)
		ft_error(USAGE);
	if ((e.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error(USAGE);
	read_files(&e, argv[1], y, i);
	fdf_mlx_init(&e);
	z_max_n_min(&e);
	print_bresenham_to_image(&e);
	mlx_hook(e.win_ptr, 2, (1L << 0), press_key, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}

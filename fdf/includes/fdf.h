/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:28:35 by grdalmas          #+#    #+#             */
/*   Updated: 2018/06/25 18:23:31 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define USAGE	"usage : ./fdf file_to_read"
# define NAME	"Le FDF de l'ennui!"
# define WIDTH			2000
# define HEIGHT 		1100
# define ESC			53
# define LEFT           123
# define DOWN           125
# define RIGHT          124
# define UP             126
# define MINUS			78
# define PLUS			69
# define KEY_B			11
# define KEY_R			15
# define KEY_PAD_5      87
# define KEY_PAD_8     	91
# define KEY_I			34
# define KEY_X			7
# define KEY_O			31
# define KEY_Z			6
# define BACKGROUND		0x1A9683EC
# define YELLOW			0x00E0CDA9
# define PALE_GREEN		0x0054F98D
# define GREEN			0x0016B84E
# define BROWN			0x00582900
# define WHITE 			0xFFFFFF
# define BLUE_W			0x001B019B

typedef struct			s_point
{
	int					x;
	int					y;
	int					color;
}						t_point;

typedef	struct			s_bresenham
{
	int					xb;
	int					yb;
	int					dx;
	int					dy;
	int					i;
	int					xinc;
	int					yinc;
	int					cumul;
}						t_bresenham;

typedef struct			s_map
{
	double				xm;
	double				ym;
	double				z;
	double				zorigin;
	int					color_map;
}						t_map;

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*mlx_img;
	char				*name;
	char				*string;
	int					image;
	int					ipanel;
	int					bpp;
	int					s_l;
	int					endian;
	void				*data;
	double				size_x;
	double				size_y;
	double				size_yo;
	double				size_xo;
	double				max_z;
	double				min_z;
	double				dist_z;
	double				moving_x;
	double				moving_y;
	int					isometric;
	int					bgrnd;
	int					fd;
	int					tmp;
	int					max_y;
	int					max_x;
	int					mod_z;
	int					check;
	int					info;
	t_point				pt1;
	t_point				pt2;
	t_bresenham			bresenham;
	t_map				**map;
}						t_env;

/*
**  fdf_init.c
*/

void					ft_error(char *str);
void					new_image(t_env *e);
void					ft_put_pixel_image(t_env *e, int y, int x, int color);
void					fdf_mlx_init(t_env *e);

/*
**  fdf_color_functs.c
*/

int						locate_colors(t_env *e, int z);
void					color_put(t_env *e);
void					info_panel2(t_env *e);
void					info_panel(t_env *e);

/*
**fdf_key_inputs.c
*/

void					origin(t_env *e);
void					info(t_env *e);
void					z_reverse(t_env *e);
int						press_key(int key, t_env *e);
void					iso_n_background(t_env *e, int key);

/*
** fdf_modif_n_move.c
*/

void					move(t_env *e);
void					zoom(t_env *e, int key);
void					size_recovery(t_env *e);
void					size_recovery_o(t_env *e);
void					modif_fdf(t_env *e, int key);

/*
**fdf_parse_struc.c
*/

void					check_character(t_env *e, char *str);
void					map_2_struct(t_env *e, char *str, int y);
t_map					**ft_create_struct(t_env *e);

/*
**fdf_print_funct.c
*/

void					put_background(t_env *e);
void					print_x(t_env *e, int x, int y);
void					print_y(t_env *e, int x, int y);

/*
**fdf_print.c
*/

void					while_print(t_env *e, int x, int y);
void					print_bresenham_to_image(t_env *e);
void					draw_vertical(t_env *e, int color);
void					draw_horizontal(t_env *e, int color);
void					draw_line(t_env *e, int color);

/*
**fdf_z_manipulations.c
*/

void					z_origin(t_env *e);
void					z_modif(t_env *e, int key);
int						is_isometric(t_env *e, int x, int y, char c);
void					z_max_to_min(t_env *e);
void					z_max_n_min(t_env *e);

/*
**fdf_main.c
*/

void					print_fdf(t_env *e);
void					gnl_check(t_env *e, char *line);
int						count_character(char *str);
void					read_files(t_env *e, char *str, int y, int i);
int						main(int argc, char **argv);

#endif

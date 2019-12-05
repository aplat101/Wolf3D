/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:08:25 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 23:40:47 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "key_map_macos.h"
# include "info.h"
# include <pthread.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct  s_point
{
    int         x;
    int			y;
}				t_point;

typedef struct  s_win
{
    void        *ptr;
    void        *win;
    void        *img_ptr;
    int         *img;
    int         nbline;
    int         cam_error;
    int         *nbwalls;
    int         **map;
	int			h_cam;
	int			fov;
    double      angle_rot;
	t_vec		*pos_cam;
    t_point     *pos_map;
	t_vec		*dir_cam;
    t_vec       *plane;
    double      cam_x;
    t_vec       *raydir;
	t_vec		*side;
	t_vec		*delta;
	t_point		*step;
	int			touch;
	int			dir_wall;
	double		dist;
	double		col;
	int			h_wall;
	int			d_start;
	int			d_end;
}               t_win;

/*
** Dir Window
*/

/*
** Ft_window.c
*/

void	ft_create_window(t_win *w);

/*
** Dir Error
*/

/*
** Ft_error.c
*/

int		ft_checkerror(int ac, char **av, t_win *w);
int		ft_checkvalidity(int fd, t_win *w);
int		ft_check_line(char *line, t_win *w);

/*
** Dir Parser
*/

/*
**  Ft_parser.c
*/

int		ft_parser(char **av, t_win *w);
int		*ft_stock_map(int i, char *line, int *map, t_win *w);
void	ft_set_cam_pos(t_win *w, int nbline, int j);
void	ft_init_values(t_win *w, int ac, char **av);

/*
**	Dir Event
*/

/*
** Ft_mlx
*/

void	ft_mlx(t_win *w);
int		close_cross(t_win *w);

/*
** Ft_bind_keys.c
*/

int		key_press(int keycode, t_win *w);

/*
** Dir Render
*/

/*
** Ft_render.c
*/

void       ft_render(t_win *w);

/*
** Dir Utils
*/

/*
** Ft_utils_error.c
*/

int		ft_valid_char(int c, t_win *w);
int		ft_check_dir(char *av);

/*
** Ft_utils_debug.c
*/

void	ft_print_all(t_win *w);
void	ft_print_map(t_win *w);

/*
** Ft_utils_parser.c
*/

void    ft_set_cam_dir(int ac, char **av, t_win *w);

#endif
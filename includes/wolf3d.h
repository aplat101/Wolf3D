/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:08:25 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:20:44 by aplat       ###    #+. /#+    ###.fr     */
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
	float		x;
	float		y;
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
	t_point		*pos_cam;
	t_vec		*dir_cam;
}               t_win;

/*
** Ft_error.c
*/

int		ft_checkerror(int ac, char **av, t_win *w);
int		ft_checkvalidity(int fd, t_win *w);
int		ft_check_line(char *line, t_win *w);

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

/*
** Ft_window.c
*/

void	ft_create_window(t_win *w);

#endif
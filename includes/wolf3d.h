/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:08:25 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:07:41 by aplat       ###    #+. /#+    ###.fr     */
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

int		ft_parser(int ac, char **av, t_win *w);
int		*ft_stock_map(char *line, int *map);

/*
** Dir Utils
*/

/*
** Ft_utils_error.c
*/

int		ft_valid_char(int c, t_win *w);

/*
** Ft_utils_debug.c
*/

void	ft_print_map(t_win *w);

#endif
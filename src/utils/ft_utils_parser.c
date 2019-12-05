/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_parser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 19:06:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 22:31:51 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void    ft_set_cam_dir(int ac, char **av, t_win *w)
{
    if (ac == 2 || (ac == 3 && ft_strcmp(av[ac - 1], "N") == 0))
    {
        w->dir_cam->x = 0;
        w->dir_cam->y = -1;
    }
    else if (ac == 3 && ft_strcmp(av[ac - 1], "S") == 0)
    {
        w->dir_cam->x = 0;
        w->dir_cam->y = 1;
    }
    else if (ac == 3 && ft_strcmp(av[ac - 1], "W") == 0)
    {
        w->dir_cam->x = -1;
        w->dir_cam->y = 0;
    }
    else if (ac == 3 && ft_strcmp(av[ac - 1], "E") == 0)
    {
        w->dir_cam->x = 1;
        w->dir_cam->y = 0;
    }
}
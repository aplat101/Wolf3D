/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_parser.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 19:06:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:55:32 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_cam_dir(int ac, char **av, t_win *w)
{
	if (ac == 2 || (ac == 3 && ft_strcmp(av[ac - 1], "N") == 0))
	{
		ft_set_vec(w->dir_cam, 0, -1);
		ft_set_vec(w->plane, 0.6, 0);
	}
	else if (ac == 3 && ft_strcmp(av[ac - 1], "S") == 0)
	{
		ft_set_vec(w->dir_cam, 0, 1);
		ft_set_vec(w->plane, -0.6, 0);
	}
	else if (ac == 3 && ft_strcmp(av[ac - 1], "W") == 0)
	{
		ft_set_vec(w->dir_cam, -1, 0);
		ft_set_vec(w->plane, 0, -0.6);
	}
	else if (ac == 3 && ft_strcmp(av[ac - 1], "E") == 0)
	{
		ft_set_vec(w->dir_cam, 1, 0);
		ft_set_vec(w->plane, 0, 0.6);
	}
}

int		ft_parser_alloc(t_win *w)
{
	if (!(w->map = (int**)malloc(sizeof(int*) * (w->nbline))))
		return (-1);
	if (!(w->nbwalls = malloc(sizeof(int) * w->nbline)))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:10:48 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 19:03:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 	mlx_hook(w->win, 3, 0, key_release, w);
**	mlx_hook(w->win, 4, 0, mouse_press, w);
**	mlx_hook(w->win, 6, 0, mouse_move, w);
*/

void	ft_mlx(t_win *w)
{
	mlx_hook(w->win, 2, 1L << 0, key_press, w);
	mlx_hook(w->win, 17, (1L << 17), close_cross, w);
	mlx_loop(w->ptr);
}

int		close_cross(t_win *w)
{
	printf("check\n");
	(void) w;
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_render.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 18:53:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:46:55 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_reset_values(t_win *w)
{
	w->pos_map->x = (int)w->pos_cam->x;
	w->pos_map->y = (int)w->pos_cam->y;
	w->touch = 0;
}

void	ft_clear(t_win *w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HH)
	{
		j = -1;
		while (++j < WD)
			w->img[(int)((i * WD) + j)] = 0;
	}
	mlx_put_image_to_window(w->ptr, w->win, w->img_ptr, 0, 0);
}

void	ft_calcul_wallx(t_win *w)
{
	if (w->dir_wall == 0)
		w->x_wall = w->pos_cam->y + w->dist * w->raydir->y;
	else
		w->x_wall = w->pos_cam->x + w->dist * w->raydir->x;
	w->t->x = (int)(w->x_wall * (double)64);
	if (w->dir_wall == 0 && w->raydir->x > 0)
		w->t->x = 64 - w->t->x - 1;
	if (w->dir_wall == 1 && w->raydir->y < 0)
		w->t->x = 64 - w->t->x - 1;
	w->t->x = abs(w->t->x);
}

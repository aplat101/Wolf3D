/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_render.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 18:53:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:36:28 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_values(t_win *w)
{
	w->cam_x = 2 * w->x / (double)WD - 1;
	w->raydir->x = w->dir_cam->x + w->plane->x * w->cam_x;
	w->raydir->y = w->dir_cam->y + w->plane->y * w->cam_x;
	w->pos_map->x = (int)w->pos_cam->x;
	w->pos_map->y = (int)w->pos_cam->y;
	w->touch = 0;
	w->delta->x = sqrt(1 + pow(w->raydir->y, 2) / pow(w->raydir->x, 2));
	w->delta->y = sqrt(1 + pow(w->raydir->x, 2) / pow(w->raydir->y, 2));
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

void	ft_calcul_hwall(t_win *w)
{
	if (w->dir_wall == 0)
		w->dist = (w->pos_map->x - w->pos_cam->x +
			(1 - w->step->x) / 2) / w->raydir->x;
	else
		w->dist = (w->pos_map->y - w->pos_cam->y +
			(1 - w->step->y) / 2) / w->raydir->y;
	w->h = (int)(w->h_wall / w->dist);
	w->d_start = (-w->h / 2) + (HH / 2);
	if (w->d_start < 0)
		w->d_start = 0;
	w->d_end = (w->h / 2) + (HH / 2);
	if (w->d_end >= HH)
		w->d_end = HH - 1;
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:48:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 23:57:22 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_render(t_win *w)
{
    int		x;

	x = -1;
	while (++x < 50)
	{
		w->cam_x = 2 * x / (double)WD - 1;
		w->raydir->x = w->dir_cam->x + w->plane->x * w->cam_x;
		w->raydir->y = w->dir_cam->y + w->plane->y * w->cam_x;
		w->delta->x = fabs(1 / w->raydir->x);
		w->delta->y = fabs(1 / w->raydir->y);
		if (w->raydir->x < 0)
		{
			w->step->x = -1;
			w->side->x = (w->pos_cam->x - w->pos_map->x) * w->delta->x;
		}
		else
		{
			w->step->x = 1;
			w->side->x = (w->pos_map->x + 1.0 - w->pos_cam->x) * w->delta->x;
		}
		if (w->raydir->y < 0)
		{
			w->step->y = -1;
			w->side->y = (w->pos_cam->y - w->pos_map->y) * w->delta->y;
		}
		else
		{
			w->step->y = 1;
			w->side->y = (w->pos_map->y + 1.0 - w->pos_cam->y) * w->delta->y;
		}
		while (w->touch == 0)
		{
			if (w->side->x < w->side->y)
			{
				w->side->x += w->delta->x;
				w->pos_map->x += w->step->x;
				w->dir_wall = 0;
			}
			else
			{
				w->side->y += w->delta->y;
				w->pos_map->y += w->step->y;
				w->dir_wall = 1;
			}
			if (w->map[w->pos_map->x][w->pos_map->y] == 1)
				w->touch = 1;
		}
		if (w->dir_wall == 0)
			w->dist = (w->pos_map->x - w->pos_cam->x + (1 - w->step->x) / 2) / w->raydir->x;
		else
			w->dist = (w->pos_map->y - w->pos_cam->y + (1 - w->step->y) / 2) / w->raydir->y;
		w->h_wall = (int)(HH / w->dist);
		w->d_start = (-w->h_wall / 2) + (HH / 2);
		if (w->d_start < 0)
			w->d_start = 0;
		w->d_end = (w->h_wall / 2) + (HH / 2);
		if (w->d_end >= HH)
			w->d_end = HH - 1;
		while (w->d_start < w->d_end)
		{
			w->img[(int)((w->d_start * WD) + x)] = 6505500;
			++(w->d_start);
		}
	}
	printf("ptr %p\n", w->ptr);
	printf("win %p\n", w->win);
	printf("img ptr %p\n", w->img_ptr);
	printf("img %p\n", w->img);
	mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
}

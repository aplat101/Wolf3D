/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:48:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 21:28:04 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_render(t_win *w)
{
	if (w->x == WD - 1)
		return ;
	while (++(w->x) < WD)
	{
//		ft_reset_values(w);
		w->cam_x = 2 * w->x / (double)WD - 1;
		w->raydir->x = w->dir_cam->x + w->plane->x * w->cam_x;
		w->raydir->y = w->dir_cam->y + w->plane->y * w->cam_x;
		ft_reset_values(w);
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
			if (w->pos_map->x < 0 || w->pos_map->x > w->nbwalls[0] - 1 || w->pos_map->y < 0 || w->pos_map->y > w->nbline - 1)
				return (ft_render(w));
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
			w->img[(int)((w->d_start * WD) + w->x)] = 6505500;
			++(w->d_start);
		}
	}
	printf("ptr %p\n", w->ptr);
	printf("win %p\n", w->win);
	printf("img ptr %p\n", w->img_ptr);
	printf("img %p\n", w->img);
}

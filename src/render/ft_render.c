/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:48:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:06:58 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_render(t_win *w)
{
	int		h;
	double	cam_x;
	int		y;
	int		d;

	h = 0;
	w->x = -1;
	while (++(w->x) < WD)
	{
		cam_x = 2 * w->x / (double)WD - 1;
		w->raydir->x = w->dir_cam->x + w->plane->x * cam_x;
		w->raydir->y = w->dir_cam->y + w->plane->y * cam_x;
		ft_reset_values(w);
		w->delta->x = sqrt(1 + pow(w->raydir->y, 2) / pow(w->raydir->x, 2));
		w->delta->y = sqrt(1 + pow(w->raydir->x, 2) / pow(w->raydir->y, 2));
		ft_determine_step(w);
		ft_take_inter(w);
		if (w->touch == 1)
		{
			if (w->dir_wall == 0)
				w->dist = (w->pos_map->x - w->pos_cam->x + (1 - w->step->x) / 2) / w->raydir->x;
			else
				w->dist = (w->pos_map->y - w->pos_cam->y + (1 - w->step->y) / 2) / w->raydir->y;
			h = (int)(w->h_wall / w->dist);
			w->d_start = (-h / 2) + (HH / 2);
			if (w->d_start < 0)
				w->d_start = 0;
			w->d_end = (h / 2) + (HH / 2);
			if (w->d_end >= HH)
				w->d_end = HH - 1;
			ft_calcul_wallx(w);
			if (w->texture == 0)
			{
				y = -1;
				while (++y < HH)
				{
					if (y < w->d_start)
						w->img[(int)((y * WD) + w->x)] = 0x00C8FF;
					else if (y > w->d_end)
						w->img[(int)((y * WD) + w->x)] = 0xB38B6D;
					else
					{
						if (w->dir_wall == 0 && w->step->x == 1)
							w->img[(int)((y * WD) + w->x)] = 0xFF0000;
						if (w->dir_wall == 0 && w->step->x == -1)
							w->img[(int)((y * WD) + w->x)] = 0xFFFF00;
						if (w->dir_wall == 1 && w->step->y == 1)
							w->img[(int)((y * WD) + w->x)] = 0xFF00FF;
						if (w->dir_wall == 1 && w->step->y == -1)
							w->img[(int)((y * WD) + w->x)] = 0x0000FF;
					}
				}
			}
			else
			{
				y = -1;
				while (++y < HH)
				{
					if (y < w->d_start)
						w->img[(int)((y * WD) + w->x)] = 0x00C8FF;
					else if (y > w->d_end)
						w->img[(int)((y * WD) + w->x)] = 0xB38B6D;
					else
					{
						d = (int)fabs(y - (HH * 0.5) + (h * 0.5));
						w->t->y = ((d * 64) / h);
						if (w->dir_wall == 0 && w->step->x == 1)
							w->img[(int)((y * WD) + w->x)] =
								w->text[5]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
						if (w->dir_wall == 0 && w->step->x == -1)
							w->img[(int)((y * WD) + w->x)] =
								w->text[1]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
						if (w->dir_wall == 1 && w->step->y == 1)
							w->img[(int)((y * WD) + w->x)] =
								w->text[4]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
						if (w->dir_wall == 1 && w->step->y == -1)
							w->img[(int)((y * WD) + w->x)] =
								w->text[0]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
					}
				}
			}
		}
		if (w->touch == 0)
		{
			y = -1;
			while (++y <= HH / 2)
				w->img[(int)((y * WD) + w->x)] = 0x00C8FF;
			y--;
			while (++y < HH)
				w->img[(int)((y * WD) + w->x)] = 0xB38B6D;
		}
	}
	mlx_put_image_to_window(w->ptr, w->win, w->img_ptr, 0, 0);
}

void		ft_determine_step(t_win *w)
{
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
}

void		ft_take_inter(t_win *w)
{
	while (w->touch == 0 && w->pos_map->x > 0 &&
			w->pos_map->x < w->nbwalls[0] - 1 &&
			w->pos_map->y < w->nbline - 1 && w->pos_map->y > 0)
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
		if (w->map[w->pos_map->y][w->pos_map->x] == 1)
			w->touch = w->map[w->pos_map->y][w->pos_map->x];
	}
}

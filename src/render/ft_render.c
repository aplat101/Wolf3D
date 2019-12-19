/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:48:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:34:28 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_render(t_win *w)
{
	int		y;

	w->x = -1;
	while (++(w->x) < WD)
	{
		ft_set_values(w);
		ft_determine_step(w);
		ft_take_inter(w);
		if (w->touch == 1)
		{
			ft_calcul_hwall(w);
			ft_calcul_wallx(w);
			ft_draw(w);
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

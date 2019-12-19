/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_window.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:44:57 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:31:34 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_create_window(t_win *w)
{
	int	bpp;
	int	s_l;
	int	endian;

	w->win = mlx_new_window(w->ptr, WD, HH, "Wolf 3D");
	w->img_ptr = mlx_new_image(w->ptr, WD, HH);
	w->img = (int*)mlx_get_data_addr(w->img_ptr, &(bpp), &(s_l), &(endian));
}

void	ft_draw_with_text(t_win *w)
{
	int	y;
	int	d;

	y = w->d_start - 1;
	while (++y < w->d_end)
	{
		d = (int)fabs(y - (HH * 0.5) + (w->h * 0.5));
		w->t->y = ((d * 64) / w->h);
		if (w->dir_wall == 0 && w->step->x == 1)
			w->img[(int)((y * WD) + w->x)] =
			w->text[3]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
		if (w->dir_wall == 0 && w->step->x == -1)
			w->img[(int)((y * WD) + w->x)] =
			w->text[1]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
		if (w->dir_wall == 1 && w->step->y == 1)
			w->img[(int)((y * WD) + w->x)] =
			w->text[2]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
		if (w->dir_wall == 1 && w->step->y == -1)
			w->img[(int)((y * WD) + w->x)] =
			w->text[0]->data[(int)(((w->t->y % 64) * 64) + (w->t->x % 64))];
	}
}

void	ft_draw_without_text(t_win *w)
{
	int	y;

	y = w->d_start - 1;
	while (++y < w->d_end)
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

void	ft_draw_sky_floor(t_win *w)
{
	int	y;

	y = -1;
	while (++y < w->d_start)
		w->img[(int)((y * WD) + w->x)] = 0x00C8FF;
	y = w->d_end - 1;
	while (++y < HH)
		w->img[(int)((y * WD) + w->x)] = 0xB38B6D;
}

void	ft_draw(t_win *w)
{
	ft_draw_sky_floor(w);
	if (w->texture == 0)
		ft_draw_without_text(w);
	else
		ft_draw_with_text(w);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 04:01:30 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:56:26 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_move_left(t_win *w)
{
	double	olddirx;
	double	oldplanex;

	olddirx = w->dir_cam->x;
	ft_set_vec(w->dir_cam,
		w->dir_cam->x * cos(-M_PI / 12) - w->dir_cam->y * sin(-M_PI / 12),
		olddirx * sin(-M_PI / 12) + w->dir_cam->y * cos(-M_PI / 12));
	oldplanex = w->plane->x;
	ft_set_vec(w->plane,
		w->plane->x * cos(-M_PI / 12) - w->plane->y * sin(-M_PI / 12),
		oldplanex * sin(-M_PI / 12) + w->plane->y * cos(-M_PI / 12));
	ft_clear(w);
	ft_render(w);
}

void		ft_move_right(t_win *w)
{
	double	olddirx;
	double	oldplanex;

	olddirx = w->dir_cam->x;
	ft_set_vec(w->dir_cam,
		w->dir_cam->x * cos(M_PI / 12) - w->dir_cam->y * sin(M_PI / 12),
		olddirx * sin(M_PI / 12) + w->dir_cam->y * cos(M_PI / 12));
	oldplanex = w->plane->x;
	ft_set_vec(w->plane,
		w->plane->x * cos(M_PI / 12) - w->plane->y * sin(M_PI / 12),
		oldplanex * sin(M_PI / 12) + w->plane->y * cos(M_PI / 12));
	ft_clear(w);
	ft_render(w);
}

void		ft_move_forward(t_win *w)
{
	double	y;
	double	x;

	y = w->pos_cam->y;
	x = w->pos_cam->x;
	if (w->map[(int)y][(int)(x + w->dir_cam->x * 0.23)] != 1
		&& (x + w->dir_cam->x * 0.23) >= 1
		&& (x + w->dir_cam->x * 0.23) < w->nbwalls[0] - 1)
		w->pos_cam->x += w->dir_cam->x * 0.23;
	if (w->map[(int)(y + w->dir_cam->y * 0.23)][(int)x] != 1
		&& (y + w->dir_cam->y * 0.23) >= 1
		&& (y + w->dir_cam->y * 0.23) < w->nbline - 1)
		w->pos_cam->y += w->dir_cam->y * 0.23;
	ft_clear(w);
	ft_render(w);
}

void		ft_move_backward(t_win *w)
{
	double	y;
	double	x;

	y = w->pos_cam->y;
	x = w->pos_cam->x;
	if (w->map[(int)y][(int)(x - w->dir_cam->x * 0.23)] != 1
		&& (x - w->dir_cam->x * 0.23) >= 1
		&& (x - w->dir_cam->x * 0.23) < w->nbwalls[0] - 1)
		w->pos_cam->x -= w->dir_cam->x * 0.23;
	if (w->map[(int)(y - w->dir_cam->y * 0.23)][(int)x] != 1
		&& (y - w->dir_cam->y * 0.23) >= 1
		&& (y - w->dir_cam->y * 0.23) < w->nbline - 1)
		w->pos_cam->y -= w->dir_cam->y * 0.23;
	ft_clear(w);
	ft_render(w);
}

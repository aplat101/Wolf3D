/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 04:01:30 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 08:35:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move_left(t_win *w)
{
	double	olddirx;
	double	oldplanex;

	olddirx = w->dir_cam->x;
	w->dir_cam->x = w->dir_cam->x * cos(-M_PI/12) - w->dir_cam->y * sin(-M_PI/12);
	w->dir_cam->y = olddirx * sin(-M_PI/12) + w->dir_cam->y * cos(-M_PI/12);
	oldplanex = w->plane->x;
	w->plane->x = w->plane->x * cos(-M_PI/12) - w->plane->y * sin(-M_PI/12);
	w->plane->y = oldplanex * sin(-M_PI/12) + w->plane->y * cos(-M_PI/12);
	ft_clear(w);
	ft_render(w);
}

void	ft_move_right(t_win *w)
{
	double	olddirx;
	double	oldplanex;

	olddirx = w->dir_cam->x;
	w->dir_cam->x = w->dir_cam->x * cos(M_PI/12) - w->dir_cam->y * sin(M_PI/12);
	w->dir_cam->y = olddirx * sin(M_PI/12) + w->dir_cam->y * cos(M_PI/12);
	oldplanex = w->plane->x;
	w->plane->x = w->plane->x * cos(M_PI/12) - w->plane->y * sin(M_PI/12);
	w->plane->y = oldplanex * sin(M_PI/12) + w->plane->y * cos(M_PI/12);
	ft_clear(w);
	ft_render(w);
}

void	ft_move_forward(t_win *w)
{
	if (w->map[(int)(w->pos_cam->y)][(int)(w->pos_cam->x + w->dir_cam->x * 0.23)] != 1)
		w->pos_cam->x += w->dir_cam->x * 0.23;
	if (w->map[(int)(w->pos_cam->y + w->dir_cam->y * 0.23)][(int)(w->pos_cam->x)] != 1)
		w->pos_cam->y += w->dir_cam->y * 0.23;
	ft_clear(w);
	ft_render(w);
}

void	ft_move_backward(t_win *w)
{
	if (w->map[(int)(w->pos_cam->y)][(int)(w->pos_cam->x - w->dir_cam->x * 0.23)] != 1)
		w->pos_cam->x -= w->dir_cam->x * 0.23;
	if (w->map[(int)(w->pos_cam->y - w->dir_cam->y * 0.23)][(int)(w->pos_cam->x)] != 1)
		w->pos_cam->y -= w->dir_cam->y * 0.23;
	ft_clear(w);
	ft_render(w);
}

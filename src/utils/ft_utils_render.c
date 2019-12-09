/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_render.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 18:53:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 21:24:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_reset_values(t_win *w)
{
	w->pos_map->x = (int)w->pos_cam->x;
	w->pos_map->y = (int)w->pos_cam->y;
//	w->plane->x += (0.6 / WD);
}
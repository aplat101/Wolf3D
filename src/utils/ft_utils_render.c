/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_render.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 18:53:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 11:13:31 by aplat       ###    #+. /#+    ###.fr     */
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
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			w->img[(int)((i * WD) + j)] = 0;
	}
	mlx_put_image_to_window(w->ptr, w->win, w->img_ptr, 0, 0);
}
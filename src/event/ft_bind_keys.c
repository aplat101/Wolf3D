/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:18:00 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 04:32:57 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_win *w)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(w->ptr, w->win);
		free(w->map);
		exit(0);
		return (0);
	}
	if (keycode == K_RIGHT)
		ft_move_right(w);
	if (keycode == K_LEFT)
		ft_move_left(w);
	if (keycode == K_UP)
		ft_move_forward(w);
	if (keycode == K_DOWN)
		ft_move_backward(w);
	return (0);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:18:00 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:18:57 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_win *w)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(w->ptr, w->win);
		exit(0);
		return (0);
	}
	return (0);
}
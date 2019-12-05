/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_window.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:44:57 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 17:46:47 by aplat       ###    #+. /#+    ###.fr     */
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
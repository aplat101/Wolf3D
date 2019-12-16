/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 10:30:47 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 13:55:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_load_textures(t_win *w)
{	
	int	wd;
	int	hh;
	int	bpp;
	int	s_l;
	int	endian;

	wd = 64;
	hh = 64;
	ft_alloc_text(w);
	w->text[0]->img = mlx_xpm_file_to_image(w->ptr, "textures/mossy.xpm", &wd, &hh);
	w->text[0]->data = (int*)mlx_get_data_addr(w->text[0]->img, &(bpp), &(s_l), &(endian));
	w->text[1]->img = mlx_xpm_file_to_image(w->ptr, "textures/redbrick.xpm", &wd, &hh);
	w->text[1]->data = (int*)mlx_get_data_addr(w->text[1]->img, &(bpp), &(s_l), &(endian));
	w->text[2]->img = mlx_xpm_file_to_image(w->ptr, "textures/sand.xpm", &wd, &hh);
	w->text[2]->data = (int*)mlx_get_data_addr(w->text[2]->img, &(bpp), &(s_l), &(endian));
	w->text[3]->img = mlx_xpm_file_to_image(w->ptr, "textures/sky.xpm", &wd, &hh);
	w->text[3]->data = (int*)mlx_get_data_addr(w->text[3]->img, &(bpp), &(s_l), &(endian));
	w->text[4]->img = mlx_xpm_file_to_image(w->ptr, "textures/stone.xpm", &wd, &hh);
	w->text[4]->data = (int*)mlx_get_data_addr(w->text[4]->img, &(bpp), &(s_l), &(endian));
	w->text[5]->img = mlx_xpm_file_to_image(w->ptr, "textures/wood.xpm", &wd, &hh);
	w->text[5]->data = (int*)mlx_get_data_addr(w->text[5]->img, &(bpp), &(s_l), &(endian));
}

void	ft_alloc_text(t_win *w)
{
	int	x;

	x = -1;
	while (++x < 6)
	{
		if (!(w->text[x] = malloc(sizeof(t_tex))))
			return ;
	}
}
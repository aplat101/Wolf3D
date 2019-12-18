/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 10:30:47 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 10:24:18 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_load_textures(t_win *w)
{	
	int	wd;
	int	hh;

	wd = 64;
	hh = 64;
	ft_alloc_text(w);
	w->text[0]->img = mlx_xpm_file_to_image(w->ptr, "textures/mossy.xpm", &wd, &hh);
	w->text[0]->data = (int*)mlx_get_data_addr(w->text[0]->img, &(w->text[0]->bpp), &(w->text[0]->s_l), &(w->text[0]->endian));
	w->text[1]->img = mlx_xpm_file_to_image(w->ptr, "textures/redbrick.xpm", &wd, &hh);
	w->text[1]->data = (int*)mlx_get_data_addr(w->text[1]->img, &(w->text[1]->bpp), &(w->text[1]->s_l), &(w->text[1]->endian));
	w->text[2]->img = mlx_xpm_file_to_image(w->ptr, "textures/sand.xpm", &wd, &hh);
	w->text[2]->data = (int*)mlx_get_data_addr(w->text[2]->img, &(w->text[2]->bpp), &(w->text[2]->s_l), &(w->text[2]->endian));
	w->text[3]->img = mlx_xpm_file_to_image(w->ptr, "textures/sky.xpm", &wd, &hh);
	w->text[3]->data = (int*)mlx_get_data_addr(w->text[3]->img, &(w->text[3]->bpp), &(w->text[3]->s_l), &(w->text[3]->endian));
	w->text[4]->img = mlx_xpm_file_to_image(w->ptr, "textures/stone.xpm", &wd, &hh);
	w->text[4]->data = (int*)mlx_get_data_addr(w->text[4]->img, &(w->text[4]->bpp), &(w->text[4]->s_l), &(w->text[4]->endian));
	w->text[5]->img = mlx_xpm_file_to_image(w->ptr, "textures/wood.xpm", &wd, &hh);
	w->text[5]->data = (int*)mlx_get_data_addr(w->text[5]->img, &(w->text[5]->bpp), &(w->text[5]->s_l), &(w->text[5]->endian));
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

void	ft_textures(t_win *w)
{
	int	res;

	res = w->texture;
	if (res == 0)
		w->texture = 1;
	else
		w->texture = 0;
	ft_clear(w);
	ft_render(w);
}

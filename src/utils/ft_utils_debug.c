/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_debug.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:56:27 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:07:21 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_print_map(t_win *w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < w->nbline)
	{
		j = -1;
		while (++j < w->nbwalls[i])
		{
			ft_putnbr(w->map[i][j]);
			if (j + 1 < w->nbwalls[i])
				ft_putchar(' ');
		}
		if (i + 1 < w->nbline)
			ft_putchar('\n');
	}
}
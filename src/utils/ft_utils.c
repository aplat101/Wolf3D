/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 18:32:41 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:36:12 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_vec(t_vec *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

void	ft_set_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

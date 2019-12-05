/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 18:20:46 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:10:05 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_valid_char(int c, t_win *w)
{
	int	tmp;

	tmp = w->cam_error;
	if (c == 48 || c == 49)
		return (1);
	if (c == 50)
	{
		if (tmp == 0)
		{
			w->cam_error = 1;
			return (1);
		}
		else
			return (0);
	}
	if (c == '\0')
		return (0);
	return (0);
}

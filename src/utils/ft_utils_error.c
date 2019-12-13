/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 18:20:46 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 07:49:37 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_valid_char(int c, t_win *w)
{
	int	tmp;

	tmp = w->cam_error;
	if (c == 48 || c == 49 || c == 51)
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

int		ft_check_dir(char *av)
{
	if (ft_strlen(av) != 1)
		return (-1);
	else if (av[0] != 'N' && av[0] != 'S' && av[0] != 'E' && av[0] != 'W')
		return (-1);
	return (0);
}

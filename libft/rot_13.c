/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rot_13.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 20:53:44 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 22:00:30 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		rot_13(int ac, char **str)
{
	int		i;

	i = 0;
	if (ac != 2)
		write(1, "\n", 1);
	if (ac == 2)
	{
		while (str[ac - 1][i])
		{
			if (ft_isupper(str[ac - 1][i]))
				str[ac - 1][i] += (str[ac - 1][i] + 13 > 90 ? -13 : 13);
			if (ft_islower(str[ac - 1][i]))
				str[ac - 1][i] += (str[ac - 1][i] + 13 > 123 ? -13 : 13);
			i++;
		}
		ft_putstr(str[ac - 1]);
		write(1, "\n", 1);
	}
}

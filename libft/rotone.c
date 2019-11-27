/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotone.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 22:00:38 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 22:07:44 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		rotone(int ac, char **str)
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
				str[ac - 1][i] += (str[ac - 1][i] + 1 > 90 ? -25 : 1);
			if (ft_islower(str[ac - 1][i]))
				str[ac - 1][i] += (str[ac - 1][i] + 1 > 123 ? -25 : 1);
			i++;
		}
		ft_putstr(str[ac - 1]);
		write(1, "\n", 1);
	}
}

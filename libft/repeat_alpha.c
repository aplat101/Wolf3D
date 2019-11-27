/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   repeat_alpha.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 19:35:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 11:57:43 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		repeat_alpha(int ac, char **str)
{
	int		repeat;

	repeat = 0;
	if (ac == 1)
		write(1, "\n", 1);
	if (ac == 2)
	{
		while (*str[ac - 1])
		{
			if (ft_isalpha(*str[ac - 1]))
			{
				repeat = (ft_islower(*str[ac - 1]) ?
				*str[ac - 1] - 96 : *str[ac - 1] - 64);
				while (repeat > 0)
				{
					ft_putchar(*str[ac - 1]);
					repeat--;
				}
			}
			else
				ft_putchar(*str[ac - 1]);
			str[ac - 1]++;
		}
		write(1, "\n", 1);
	}
}

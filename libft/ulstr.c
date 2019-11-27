/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ulstr.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 20:31:11 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 20:42:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ulstr(int ac, char **str)
{
	if (ac != 2)
		write(1, "\n", 1);
	if (ac == 2)
	{
		while (*str[ac - 1])
		{
			if (ft_islower(*str[ac - 1]))
				ft_putchar(*str[ac - 1] - 32);
			else if (ft_isupper(*str[ac - 1]))
				ft_putchar(*str[ac - 1] + 32);
			else
				ft_putchar(*str[ac - 1]);
			str[ac - 1]++;
		}
		write(1, "\n", 1);
	}
}

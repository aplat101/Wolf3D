/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   search_and_replace.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 20:00:55 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 20:26:16 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		search_and_replace(int ac, char **str)
{
	if (ac != 4 || ft_strlen(str[ac - 1]) != 1 || ft_strlen(str[ac - 2]) != 1)
		write(1, "\n", 1);
	else
	{
		while (*str[ac - 3])
		{
			if (*str[ac - 3] == *str[ac - 2])
				*str[ac - 3] = *str[ac - 1];
			ft_putchar(*str[ac - 3]);
			str[ac - 3]++;
		}
		write(1, "\n", 1);
	}
}

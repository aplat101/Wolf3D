/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rev_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 23:03:25 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 11:57:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		rev_print(int ac, char **str)
{
	size_t	cmp;

	cmp = 0;
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		cmp = ft_strlen(str[ac - 1]);
		while (cmp-- > 0)
			ft_putchar(str[ac - 1][cmp]);
	}
}

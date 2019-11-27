/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maff_revalpha.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:45:55 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 11:54:59 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		maff_revalpha(void)
{
	char	start;

	start = 'z';
	while (start != 96)
	{
		if (start % 2 == 1)
			ft_putchar(start - 32);
		else
			ft_putchar(start);
		start--;
	}
	write(1, "\n", 1);
}

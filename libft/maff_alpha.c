/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maff_alpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:59:06 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 11:54:49 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		maff_alpha(void)
{
	char	start;

	start = 'a';
	while (start != 123)
	{
		if (start % 2 == 0)
			ft_putchar(start - 32);
		else
			ft_putchar(start);
		start++;
	}
	write(1, "\n", 1);
}

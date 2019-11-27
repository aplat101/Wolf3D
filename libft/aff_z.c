/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff_z.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 19:15:26 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 19:15:52 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	aff_z(int ac, char *str)
{
	if (ac == 2)
	{
		while (*str != 'z')
			str++;
		if (*str == 'z')
			write(1, "z\n", 2);
	}
	if (ac == 1)
		write(1, "z\n", 2);
}

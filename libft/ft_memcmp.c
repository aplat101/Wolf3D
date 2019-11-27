/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:43:43 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 20:16:26 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned const char	*d1;
	unsigned const char	*d2;

	i = 0;
	d1 = s1;
	d2 = s2;
	while (i < n)
	{
		if (*(d1 + i) != *(d2 + i))
			return (*(d1 + i) - *(d2 + i));
		i++;
	}
	return (0);
}

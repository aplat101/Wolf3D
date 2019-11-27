/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:09:03 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 20:17:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	const char		*s;
	char			*d;

	s = src;
	d = dest;
	if (src >= dest)
		ft_memcpy(d, s, n);
	else
	{
		s += n;
		d += n;
		while (n > 0)
		{
			*--d = *--s;
			n--;
		}
	}
	return (dest);
}

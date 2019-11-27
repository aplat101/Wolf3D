/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 16:16:05 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 00:45:05 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*tmpd;
	unsigned char	*tmps;

	x = 0;
	tmpd = (unsigned char*)dest;
	tmps = (unsigned char*)src;
	while (x < n)
	{
		tmpd[x] = tmps[x];
		if (tmps[x] == (unsigned char)c)
			return (tmpd + x + 1);
		x++;
	}
	return (NULL);
}

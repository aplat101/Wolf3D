/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:36:32 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 00:48:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	s = src;
	d = dest;
	i = 0;
	while (src != '\0' && i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	while (i < n)
	{
		*d = '\0';
		d++;
		i++;
	}
	return (dest);
}

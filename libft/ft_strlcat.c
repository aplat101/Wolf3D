/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:42:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:37:48 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (n < d)
		return (s + n);
	while (d + i < n - 1 && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	if (d + i < n)
		dest[d + i] = '\0';
	dest[d + i] = '\0';
	return (d + s);
}

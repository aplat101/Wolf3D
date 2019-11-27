/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:40:29 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:14:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	id;
	int	is;

	id = 0;
	while (dest[id])
		id++;
	is = 0;
	while (src[is])
	{
		dest[id + is] = src[is];
		is++;
	}
	dest[id + is] = '\0';
	return (dest);
}

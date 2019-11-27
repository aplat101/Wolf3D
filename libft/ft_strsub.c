/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 17:06:17 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:54:46 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!(str = ft_strnew(len)))
		return (NULL);
	ptr = str;
	if (s != NULL)
	{
		while (len--)
		{
			*str = s[start];
			str++;
			start++;
		}
		*str = '\0';
	}
	return (ptr);
}

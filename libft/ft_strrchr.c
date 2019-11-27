/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:42:00 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:51:41 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = -1;
	while (s[i])
	{
		if (s[i] == c)
			tmp = i;
		i++;
	}
	if (s[i] == '\0' && tmp != -1)
		return ((char *)&s[tmp]);
	if (c == 0 && s[i] == c)
		return ((char *)&s[i]);
	if (s[i] == '\0' && s[i] != c)
		return (NULL);
	return (NULL);
}

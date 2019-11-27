/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 17:54:56 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 20:19:05 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	str = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i + j] = s2[j];
		str[i + j] = '\0';
	}
	return (str);
}

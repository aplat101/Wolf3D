/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fstrjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 13:46:37 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 17:28:45 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(const char **s1, const char **s2, int free_s1, int free_s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	str = 0;
	if (*s1 != NULL && *s2 != NULL)
	{
		if (!(str = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2) + 1)))
			return (NULL);
		while (*s1[++i])
			str[i] = *s1[i];
		while (*s2[++j])
			str[i + j] = *s2[j];
		str[i + j] = '\0';
	}
	if (free_s1)
		ft_memdel(*s1);
	if (free_s2)
		ft_memdel(*s2);
	return (str);
}

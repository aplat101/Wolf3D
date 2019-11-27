/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 22:01:32 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:18:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strreturn(char **ret, int nbw, char c, char *s)
{
	int		j;
	int		wlen;

	j = 0;
	wlen = 0;
	while (j < nbw && *s != '\0')
	{
		if (*s != c)
		{
			wlen = ft_wordlen(s, c);
			if (!(ret[j] = (char *)malloc(sizeof(char) * (wlen + 1))))
				return (NULL);
			wlen = 0;
			while (*s != c && *s != '\0')
				ret[j][wlen++] = *(s++);
			ret[j][wlen] = '\0';
			j++;
		}
		else
			s++;
	}
	return (ret);
}

char		**ft_strsplit(const char *s, char c)
{
	int		nbw;
	char	**ret;

	if (s == NULL)
		return (NULL);
	nbw = ft_countwords(s, c);
	if (!(ret = (char **)malloc(sizeof(char*) * (nbw + 1))))
		return (NULL);
	ret[nbw] = NULL;
	ret = ft_strreturn(ret, nbw, c, (char*)s);
	return (ret);
}

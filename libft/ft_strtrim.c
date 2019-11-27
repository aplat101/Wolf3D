/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 12:53:19 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:41:16 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(const char *s)
{
	int		len;
	int		i;
	char	*str;

	str = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (iswhitespaces(s[len - 1]) == 1)
		len--;
	i = -1;
	while (iswhitespaces(s[++i]))
		len--;
	if (len <= 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}

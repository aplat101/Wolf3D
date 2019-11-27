/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwords.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 14:08:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 22:45:25 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char c)
{
	int	i;
	int	nbw;

	i = 0;
	nbw = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			nbw++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (nbw);
}

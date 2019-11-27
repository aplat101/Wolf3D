/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:06:08 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:21:42 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nb)
{
	int		lenb;
	char	*res;
	int		neg;

	lenb = 9;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb / ft_power(10, lenb) == 0 && lenb > 0)
		lenb--;
	lenb = ((nb < 0) ? lenb + 2 : lenb + 1);
	neg = ((nb < 0) ? 1 : 0);
	nb = ((nb < 0) ? nb *= -1 : nb);
	if (!(res = (char *)malloc(sizeof(char) * lenb + 1)))
		return (NULL);
	res[lenb] = '\0';
	while (lenb > 0)
	{
		res[lenb - 1] = (nb % 10) + '0';
		nb = nb / 10;
		lenb--;
	}
	((neg == 1) ? res[0] = '-' : neg++);
	return (res);
}

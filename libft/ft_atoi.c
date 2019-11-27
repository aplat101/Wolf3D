/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:40:39 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 13:21:04 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				i;
	int				neg;
	int				nb;

	i = 0;
	neg = 0;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n' ||
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	if (*str == '-' && *(str - 1) != '+')
	{
		neg = 1;
		str++;
	}
	while (*str < 58 && *str > 47)
	{
		nb = nb * 10;
		nb = nb + *str - '0';
		str++;
	}
	return (neg ? nb *= -1 : nb);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:45:29 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 20:27:42 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcapitalize(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_islower(s[i]) == 1)
		s[i] -= 32;
	while (s[i])
	{
		if (ft_islower(s[i]) == 1)
			if (s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == ' ' ||
					s[i - 1] == '\n' || s[i - 1] == '\t')
				s[i] -= 32;
		if (ft_isupper(s[i]) == 1)
			if (ft_isdigit(s[i - 1]) || ft_isalpha(s[i - 1]))
				s[i] += 32;
		i++;
	}
	return (s);
}

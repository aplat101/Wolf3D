/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 03:33:28 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 04:15:16 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*t;
	t_list	*n;

	t = *alst;
	while (t)
	{
		n = t->next;
		del(t->content, t->content_size);
		free(t);
		t = n;
	}
	*alst = NULL;
}

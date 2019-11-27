/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 04:43:28 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:53:38 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*name;
	t_list	*tmp;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(begin = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	name = begin;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(name->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		name = name->next;
		lst = lst->next;
	}
	return (begin);
}

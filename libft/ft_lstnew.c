/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 23:57:00 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 01:50:40 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	if (!(t = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(t->content = (void*)ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(t->content, content, content_size);
		t->content_size = content_size;
	}
	else
	{
		t->content = NULL;
		t->content_size = 0;
	}
	t->next = NULL;
	return (t);
}

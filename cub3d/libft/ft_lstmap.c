/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:56:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/12 16:49:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmplst;
	t_list	*ret;

	ret = 0;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		tmplst = ft_lstnew(f(lst->content));
		if (!tmplst)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmplst);
		lst = lst->next;
	}
	return (ret);
}

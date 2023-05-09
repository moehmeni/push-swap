/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:37:39 by mmomeni           #+#    #+#             */
/*   Updated: 2023/04/22 00:57:43 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*start;
	t_list	*node;
	int		content;

	if (!lst || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(&start);
			return (NULL);
		}
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}

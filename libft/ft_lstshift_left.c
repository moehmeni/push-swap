/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:19:22 by mmomeni           #+#    #+#             */
/*   Updated: 2023/04/23 19:51:30 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstshift_left(t_list **lst)
{
	t_list	*node;

	if (!lst || !(*lst) || !((*lst)->next))
		return ;
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = *lst;
	*lst = (*lst)->next;
	node->next->next = NULL;
}

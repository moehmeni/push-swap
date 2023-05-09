/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:03:16 by mmomeni           #+#    #+#             */
/*   Updated: 2023/04/23 18:17:56 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstshift_right(t_list **lst)
{
	t_list	*node;

	if (!lst || !(*lst) || !((*lst)->next))
		return ;
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = *lst;
	*lst = node;
	node = *lst;
	while (node->next != *lst)
		node = node->next;
	node->next = NULL;
}

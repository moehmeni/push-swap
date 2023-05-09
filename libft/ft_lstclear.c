/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:07:30 by mmomeni           #+#    #+#             */
/*   Updated: 2023/04/22 00:54:58 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next_tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		next_tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = next_tmp;
	}
	*lst = NULL;
}

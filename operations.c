/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:17:10 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/05 15:39:59 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **s1, t_list **s2, char *print)
{
	t_list	*tmp;

	if (s1)
	{
		if (ft_lstsize(*s1) < 2)
			return (1);
		tmp = *s1;
		*s1 = (*s1)->next;
		tmp->next = (*s1)->next;
		(*s1)->next = tmp;
	}
	if (s2)
	{
		if (ft_lstsize(*s2) < 2)
			return (1);
		tmp = *s2;
		*s2 = (*s2)->next;
		tmp->next = (*s2)->next;
		(*s2)->next = tmp;
	}
	if (print)
		ft_putendl_fd(print, STDOUT_FILENO);
	return (1);
}

int	rotate(t_list **s1, t_list **s2, int reverse, char stack)
{
	if (reverse)
		ft_lstshift_right(s1);
	else
		ft_lstshift_left(s1);
	if (s2)
	{
		if (reverse)
			ft_lstshift_right(s2);
		else
			ft_lstshift_left(s2);
	}
	if (stack)
	{
		if (reverse)
			ft_putchar_fd('r', STDOUT_FILENO);
		ft_putchar_fd('r', STDOUT_FILENO);
		ft_putchar_fd(stack, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (1);
}

int	push(t_list **from, t_list **to, char *print)
{
	t_list	*node;

	if (!from || !*from)
		return (1);
	node = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, node);
	if (print)
		ft_putendl_fd(print, STDOUT_FILENO);
	return (1);
}

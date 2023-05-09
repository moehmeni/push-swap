/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:03:54 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/07 20:35:59 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_count(t_list *s, int weight)
{
	int	n;

	n = 0;
	while (s && s->weight != weight)
	{
		s = s->next;
		n++;
	}
	return (n);
}

int	sort_3(t_list **s)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(*s))
		return (1);
	a = (*s)->content;
	b = (*s)->next->content;
	c = (*s)->next->next->content;
	if (a > b && b < c && a < c)
		return (swap(s, NULL, "sa"));
	else if ((a > c && c > b) || (c > a && a > b))
		return (rotate(s, NULL, 0, 'a'));
	else if (b > a && a > c)
		return (rotate(s, NULL, 1, 'a'));
	swap(s, NULL, "sa");
	rotate(s, NULL, (a > b && b > c) || (c > b && b > a), 'a');
	return (1);
}

void	sort_5(t_list **sa, t_list **sb)
{
	int	len;
	int	i;
	int	w;
	int	r;

	len = ft_lstsize(*sa);
	i = 0;
	w = 0;
	while (i++ < len - 3)
	{
		r = rotate_count(*sa, w);
		while ((*sa)->weight != w)
			rotate(sa, NULL, r > len - r, 'a');
		push(sa, sb, "pb");
		w++;
	}
	sort_3(sa);
	while (*sb)
		push(sb, sa, "pa");
}

void	sort(t_list **sa, t_list **sb)
{
	int	i;
	int	len;
	int	threshold;

	i = 0;
	len = ft_lstsize(*sa);
	threshold = nearest_sq(len) * 1.4;
	while (*sa)
	{
		if ((*sa)->weight <= threshold + i)
		{
			push(sa, sb, "pb");
			if ((*sb)->weight <= i++)
				rotate(sb, NULL, 0, 'b');
		}
		else
			rotate(sa, NULL, 0, 'a');
	}
	while (len--)
	{
		i = rotate_count(*sb, len);
		while ((*sb)->weight != len)
			rotate(sb, NULL, i > len - i, 'b');
		push(sb, sa, "pa");
	}
}

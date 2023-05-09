/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:14:14 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/08 22:53:46 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int n, int *nums, int size)
{
	int	i;

	i = 0;
	while (size--)
	{
		if (nums[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	is_str_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_list *s)
{
	t_list	*current;

	current = s;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	nearest_sq(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i - 1);
}

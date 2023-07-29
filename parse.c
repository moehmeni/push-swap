/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:38:15 by mmomeni           #+#    #+#             */
/*   Updated: 2023/07/29 15:12:44 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	terminate(t_list **sa, t_list **sb, int error)
{
	if (sa && *sa)
		ft_lstclear(sa);
	if (sb && *sb)
		ft_lstclear(sb);
	if (error)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (error);
}

int	is_dup(t_list *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	init_weights(t_list *sa)
{
	t_list	*node;
	t_list	*head;
	int		n;
	int		i;
	int		*nums;

	n = ft_lstsize(sa);
	nums = malloc(n * sizeof(int));
	i = 0;
	node = sa;
	head = node;
	while (n--)
	{
		nums[i++] = node->content;
		node = node->next;
	}
	nums = ft_bubblesort(nums, i);
	while (head)
	{
		head->weight = get_index(head->content, nums, i);
		head = head->next;
	}
}

int	init_stack(t_list **sa, t_list **sb, int argc, char **argv)
{
	char	**nums;
	int		i;

	nums = NULL;
	while (argc-- > 1)
	{
		i = 0;
		nums = ft_split(argv[argc], ' ');
		if (!nums || !nums[0])
			return (terminate(sa, sb, 0));
		while (nums[i])
			i++;
		while (i--)
		{
			if (!is_str_num(nums[i]) || is_dup(*sa, ft_atoi(nums[i])))
				return (terminate(sa, sb, 1));
			if (ft_atoi(nums[i]) > INT32_MAX || ft_atoi(nums[i]) < INT32_MIN)
				return (terminate(sa, sb, 1));
			ft_lstadd_front(sa, ft_lstnew(ft_atoi(nums[i])));
		}
		ft_free_split(nums);
	}
	return (0);
}

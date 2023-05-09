/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:36:08 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/07 20:56:57 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	exec(char *code, t_list **sa, t_list **sb)
{
	if (!ft_strncmp(code, "sa", 2))
		return (swap(sa, NULL, 0));
	if (!ft_strncmp(code, "sb", 2))
		return (swap(NULL, sb, 0));
	if (!ft_strncmp(code, "ss", 2))
		return (swap(sa, sb, 0));
	if (!ft_strncmp(code, "pa", 2))
		return (push(sb, sa, 0));
	if (!ft_strncmp(code, "pb", 2))
		return (push(sa, sb, 0));
	if (!ft_strncmp(code, "ra", 2))
		return (rotate(sa, NULL, 0, 0));
	if (!ft_strncmp(code, "rb", 2))
		return (rotate(sb, NULL, 0, 0));
	if (!ft_strncmp(code, "rr", 3))
		return (rotate(sa, sb, 0, 0));
	if (!ft_strncmp(code, "rra", 3))
		return (rotate(sa, NULL, 1, 0));
	if (!ft_strncmp(code, "rrb", 3))
		return (rotate(sb, NULL, 1, 0));
	if (!ft_strncmp(code, "rrr", 3))
		return (rotate(sa, sb, 1, 0));
	return (0);
}

int	get_from_input(t_list **sa, t_list **sb)
{
	char	*code;

	while (1)
	{
		code = get_next_line(STDIN_FILENO);
		if (!code)
			break ;
		if (!exec(code, sa, sb))
			return (0);
		free(code);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*sa;
	t_list	*sb;
	int		error;

	sa = NULL;
	sb = NULL;
	if (argc < 2)
		return (terminate(&sa, &sb, 0));
	error = init_stack(&sa, &sb, argc, argv);
	if (error)
		return (error);
	init_weights(sa);
	if (!get_from_input(&sa, &sb))
		return (terminate(&sa, &sb, 1));
	if (is_sorted(sa) && ft_lstsize(sb) == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (terminate(&sa, &sb, 0));
}

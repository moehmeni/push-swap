/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:10:42 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/07 20:38:00 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (is_sorted(sa))
		return (terminate(&sa, &sb, 0));
	if (ft_lstsize(sa) == 2)
		swap(&sa, NULL, "sa");
	else if (ft_lstsize(sa) == 3)
		sort_3(&sa);
	else if (ft_lstsize(sa) <= 5)
		sort_5(&sa, &sb);
	else
		sort(&sa, &sb);
	return (terminate(&sa, &sb, 0));
}

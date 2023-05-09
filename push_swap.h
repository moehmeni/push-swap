/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:26:47 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/07 20:28:43 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

/* Algo */

int		sort_3(t_list **s);
void	sort_5(t_list **sa, t_list **sb);
void	sort(t_list **sa, t_list **sb);

/* Operations */

int		swap(t_list **s1, t_list **s2, char *print);
int		rotate(t_list **s1, t_list **s2, int reverse, char stack);
int		push(t_list **from, t_list **to, char *print);

/* Utils */

int		get_index(int n, int *nums, int size);
int		is_str_num(char *s);
int		is_sorted(t_list *s);
int		nearest_sq(int n);

/* Data Validation */

void	init_weights(t_list *sa);
int		init_stack(t_list **sa, t_list **sb, int argc, char **argv);
int		terminate(t_list **sa, t_list **sb, int error);
int		is_dup(t_list *stack, int n);

#endif
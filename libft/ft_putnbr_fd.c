/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:00:34 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/28 15:42:12 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MAX)
		return (ft_putstr_fd("2147483647", fd));
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

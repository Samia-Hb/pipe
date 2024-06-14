/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:27:33 by shebaz            #+#    #+#             */
/*   Updated: 2023/11/29 20:28:24 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_div(unsigned int n, int divisor)
{
	while (n / divisor >= 10)
		divisor *= 10;
	return (divisor);
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	int	divisor;

	divisor = 1;
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	divisor = ft_div(n, divisor);
	while (divisor > 0)
	{
		ft_putchar(n / divisor + '0', count);
		n %= divisor;
		divisor /= 10;
	}
}

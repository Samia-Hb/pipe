/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:16:22 by shebaz            #+#    #+#             */
/*   Updated: 2023/12/09 21:30:26 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_div(int n, int divisor)
{
	while (n / divisor >= 10)
		divisor *= 10;
	return (divisor);
}

void	ft_putnbr_signed(int m, int *count)
{
	int	divisor;

	divisor = 1;
	if (m == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (m < 0)
	{
		ft_putchar('-', count);
		m = -m;
	}
	divisor = ft_div(m, divisor);
	while (divisor > 0)
	{
		ft_putchar(m / divisor + '0', count);
		m %= divisor;
		divisor /= 10;
	}
}

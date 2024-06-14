/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:16:07 by shebaz            #+#    #+#             */
/*   Updated: 2023/11/29 20:38:05 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char c, int *count)
{
	char	*t;

	if (c == 'X')
		t = "0123456789ABCDEF";
	else
		t = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, c, count);
		ft_putchar(t[nbr % 16], count);
	}
	else if (nbr < 10)
		ft_putchar(nbr + 48, count);
	else
		ft_putchar(t[nbr % 16], count);
}

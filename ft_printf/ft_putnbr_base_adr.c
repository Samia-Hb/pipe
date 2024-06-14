/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_adr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:39:50 by shebaz            #+#    #+#             */
/*   Updated: 2023/11/30 22:30:00 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_adr(unsigned long nbr, char c, int *count)
{
	char	*t;

	t = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbr_base_adr(nbr / 16, c, count);
		ft_putchar(t[nbr % 16], count);
	}
	else if (nbr < 10)
		ft_putchar(nbr + 48, count);
	else
		ft_putchar(t[nbr % 16], count);
}

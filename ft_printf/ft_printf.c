/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:15:43 by shebaz            #+#    #+#             */
/*   Updated: 2023/12/09 22:08:12 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(char c, va_list ap, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_signed(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), c, count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_base_adr(va_arg(ap, unsigned long), c, count);
	}
	else if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == '%')
		ft_putchar(c, count);
}

static void	ft_tmp(char c, int *i, int *count)
{
	ft_putchar(c, count);
	*i = *i + 1;
}

static void	ft_valid(char c, va_list ap, int *count, int *i)
{
	if (c == 'd' || c == 'c' || c == 'i' || c == 's' || c == 'p' || c == '%'
		|| c == 'x' || c == 'X' || c == 'u')
	{
		check(c, ap, count);
		*i += 2;
	}
	else
		*i += 1;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_tmp(str[i], &i, &count);
		else if (str[i] == '%' && str[i + 1])
			ft_valid(str[i + 1], ap, &count, &i);
		else
			i++;
	}
	va_end(ap);
	return (count);
}

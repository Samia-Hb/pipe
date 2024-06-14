/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:30:37 by shebaz            #+#    #+#             */
/*   Updated: 2023/12/02 15:33:52 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_putnbr_signed(int n, int *count);
void	ft_putnbr_base(unsigned int nbr, char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putchar(int c, int *count);
void	ft_putnbr_base_adr(unsigned long nbr, char c, int *count);
int		ft_printf(const char *str, ...);

#endif

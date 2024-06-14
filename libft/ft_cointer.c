/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:55:39 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/13 21:13:29 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(char *str, char c) //work
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			word_counter++;
			while (str[i + 1] == c)
			{
				i++;
			}
		}
		i++;
	}
	if (str[0] != c && str[ft_strlen(str) - 1] != c)
		word_counter++;
	if (str[0] == c && str[ft_strlen(str) - 1] == c)
		word_counter--;
	return (word_counter);
}

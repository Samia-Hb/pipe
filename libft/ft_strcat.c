/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 08:40:50 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/15 10:12:45 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_s(char *s)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
			j++;
		i++;
	}
	i = 0;
	if (s[0] == 39 && s[ft_strlen(s) - 1] == 39 && j > 2
		&& ft_counter(s, ' ') > 1)
	{
		while (s[i])
		{
			if (s[i] == 39)
				s[i] = ' ';
			i++;
		}
	}
	return (s);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src || !dest)
		return (NULL);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

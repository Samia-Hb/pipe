/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:47:15 by shebaz            #+#    #+#             */
/*   Updated: 2024/05/20 21:58:21 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**trim_string(char **s, char **old)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (s[i])
	{
		if (s[i][0] == '\'' && s[i][strlen(s[i]) - 1] == '\'')
		{
			trimmed = ft_strtrim(s[i], "'");
			if (trimmed)
			{
				free(s[i]);
				s[i] = trimmed;
			}
		}
		i++;
	}
	i = 0;
	while (old[i])
	{
		free(old[i]);
		i++;
	}
	free(old);
	return (s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:12 by shebaz            #+#    #+#             */
/*   Updated: 2024/05/20 09:26:53 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_str(char *s1, char *s2)
{
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;
	int		j;
	char	*checkresult;

	i = 0;
	j = 0;
	checkresult = check_str(s1, s2);
	if (checkresult)
		return (checkresult);
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:16:48 by shebaz            #+#    #+#             */
/*   Updated: 2024/05/18 23:27:32 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	dest_length;
	int	i;

	dest_length = 0;
	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (dst[dest_length] && dest_length < dstsize)
		dest_length++;
	if (dstsize > 0 && dest_length < dstsize - 1)
	{
		while (src[i] && dest_length + i < dstsize - 1)
		{
			dst[dest_length + i] = src[i];
			i++;
		}
		dst[dest_length + i] = '\0';
	}
	while (src[i])
		i++;
	return (dest_length + i);
}

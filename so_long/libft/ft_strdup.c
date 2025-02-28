/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:47:57 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 10:48:05 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

char	*ft_strdup(const char *str)
{
	size_t	s_len;
	size_t	i;
	char	*ptr;

	if (!str)
		return (NULL);
	s_len = ft_strlen((char *)str);
	ptr = malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s_len > i)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

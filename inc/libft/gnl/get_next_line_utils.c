/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:40:56 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 12:40:56 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	len_s1 = ft_strlen_until(s1, '\0');
	len_s2 = ft_strlen_until(s2, '\0');
	i = 0;
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		res[len_s1++] = s2[i++];
	res[len_s1] = '\0';
	return (res);
}

size_t	ft_strlen_until(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

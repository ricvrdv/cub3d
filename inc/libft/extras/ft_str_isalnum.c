/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:39:47 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 12:39:49 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

//info --> check if a string is numbers, letters or symbols

int	ft_str_isalnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 33 && c[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}

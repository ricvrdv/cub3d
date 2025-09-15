/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:53:50 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 18:49:30 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//info   --> Compare the first n bytes of s1 and s2
//s1     --> Pointer to the first str
//s2     --> Pointer to the second str
//count  --> Number of bytes to compare
//return --> Success (0)
//return --> Failure (Difference between both str)

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <string.h>
// #include <stdio.h>
// #include "ft_strlen.c"
// int	main(int ac, char **av)
// {
//	if (ac > 2)
//	{   
//  	printf("ft_strncmp: %i\n", ft_strncmp(av[1], av[2], ft_strlen(av[1])));
// 		printf("strncmp: %i", strncmp(av[1], av[2], ft_strlen(av[1])));
//	}
// 	return(0);
// }
